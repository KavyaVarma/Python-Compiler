#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
#define MAX_VAR_LEN 20
#define MAX_STR_LEN 50

enum type{int_type, float_type, string_type, bool_type, list_type};

typedef struct node
{
	struct node *child,*next;
	char *token;
} node;

struct item_list
{
	char var_name[MAX_VAR_LEN];	// max variable name length
	enum type var_type;
	int line_num;
	void* value;
	struct item_list* next_item;
};

struct scope
{
	struct scope* parent_scope;
	struct scope* next_in_scope;
	struct scope* child_scope;
	struct item_list* var_items;
	int position;	//position wrt the parent
};


struct datatype* util(struct scope* curr_scope,char* var_name);

struct datatype* indexChecker(struct datatype* given, char* indices)
{
	struct datatype* newval = (struct datatype*)malloc(sizeof(struct datatype));
	char* value = (char*)(given->sval);
	if(given->val_type!=list_type)
	{
		newval->val_type = -1;	//Not indexable
		return newval;
	}

	char* token = strtok(indices," ");
	int ind;
	int i = 0;
	int tracker = 0;
	while(token!=NULL)
	{
		ind = atoi(token);
		if(value[i]!='[')
		{
			newval->val_type = -1;	//Not indexable
			return newval;
		}
		i = i+1;
		while(ind!=0)
		{
			if(value[i]=='[')
			{
				i++;
				tracker++;
			}
			while(value[i]!=' ' || tracker!=0)
			{
				if(value[i]==']')
					tracker--;
				if(tracker<0)
				{
					newval->val_type = -2;	//Index out of range
					return newval;
				}
				i++;
			}
			if(value[i]==' ' && tracker==0)
			{
				ind--;
				i++;
			}
			else
			{
				newval->val_type = -2;	//Index out of range
				return newval;
			}
		}
		token = strtok(NULL, " ");
	}
	int j = i;
	tracker = 0;
	if(value[j]=='[')
	{
		newval->val_type = list_type;
		tracker++;
	}
	else
	{
		newval->val_type = float_type;
	}
	j++;
	while(tracker!=0)
	{
		if(value[j]==']')
			tracker--;
		j++;
	}
	strncpy(newval->sval,value+i, j-i);
	newval->sval[j-i] = '\0';
	if(newval->val_type==float_type)
	{
		newval->numval = atof(newval->sval);
	}
	return newval;
}

struct datatype* lookup(struct scope* curr_scope, char* var_name, char* indices)
{
	struct scope* temp=curr_scope;
	
	while(temp){
		if(util(temp,var_name)==NULL){
			if(temp->parent_scope)
				temp=temp->parent_scope;
			else
				return NULL;
		}
		else
		{
			if(strcmp(indices,"")==0)
				return util(temp, var_name);
			return indexChecker(util(temp,var_name), indices);
		}
	}
}


struct datatype* util(struct scope* curr_scope,char* var_name){ //Just wrote a util function because easier to traverse parent scopes
	if(curr_scope->var_items==NULL)
		return NULL;
	struct item_list* temp = curr_scope->var_items;

	int flag=0;
	struct datatype *id=(struct datatype*)malloc(sizeof(struct datatype)); //malloc because local variables on stack can't be returned
	while(temp!=NULL){
		if(strcmp(temp->var_name,var_name)==0){
			//printf("%s %s\n",temp->var_name,var_name);
			id->val_type=temp->var_type;
			if(temp->var_type==int_type || temp->var_type==bool_type){
				id->numval=(int)*((float*)temp->value); //Typecast it as it is float numval
			}
			if(temp->var_type==float_type)
				id->numval=*((float*)temp->value);
			if(temp->var_type==string_type || temp->var_type==list_type)
				strcpy(id->sval,(char*)temp->value);
			flag=1;
			
		}
		temp = temp->next_item;
	}
	if(flag==1)
		return id;
	else{
		free(id); //To free space
		if(curr_scope->parent_scope)
			return util(curr_scope->parent_scope,var_name);  //Try to find variable in parent scope
	}
}

struct scope* create_scope(struct scope* parent)
{
	struct scope* new_scope = (struct scope*)malloc(sizeof(struct scope));
	new_scope->parent_scope = parent;
	new_scope->next_in_scope = NULL;
	new_scope->child_scope = NULL;

	if(parent->child_scope==NULL)
	{
		new_scope->position = 1;
		parent->child_scope = new_scope;
		return new_scope;
	}
	struct scope* temp = parent->child_scope;
	int k = 2;
	while(temp->next_in_scope!=NULL)
	{
		k++;
		temp = temp->next_in_scope;
	}
	new_scope->position = k;
	temp->next_in_scope = new_scope;
	return new_scope;
}

int add_variable(struct scope* current_scope, char* var_name, enum type data_type, int line_num, void* value)
{
	struct item_list* new_item = (struct item_list*)malloc(sizeof(struct item_list));
	strcpy(new_item->var_name, var_name);
	new_item->var_type = data_type;
	new_item->line_num = line_num;
	new_item->next_item = NULL;

	if(data_type==int_type || data_type==bool_type)
	{
		new_item->value = (void*)malloc(sizeof(int));
		*((int*)new_item->value) = *((int*)value);
	}

	if(data_type==float_type)
	{
		new_item->value = (void*)malloc(sizeof(float));
		*((float*)new_item->value) = *((float*)value);
	}
	
	if(data_type==string_type || data_type==list_type)
	{
		new_item->value=(void*)malloc(sizeof(char)*MAX_STR_LEN);
		strcpy((char*)new_item->value, (char*)value);
	}
	
	if(current_scope->var_items==NULL)
	{
		current_scope->var_items = new_item;
		return 1;
	}

	struct item_list* temp = current_scope->var_items;

	while(temp->next_item!=NULL)
		temp = temp->next_item;

	temp->next_item = new_item;
	return 1;
}

struct scope* enter_scope(struct scope* current_scope, int scope_number)
{
	if(current_scope->child_scope==NULL)
		return NULL;
	int k = 1;

	struct scope* temp = current_scope->child_scope;

	while(k!=scope_number && temp->next_in_scope!=NULL)
	{
		k++;
		temp = temp->next_in_scope; 
	}

	if(k==scope_number)
		return temp;
	return NULL;
}

struct scope* exit_scope(struct scope* current_scope)
{
	return current_scope->parent_scope;
}

/*int lookup(struct scope* current_scope, char* var_name)
{
    struct item_list* temp2 = current_scope->var_items;
    while(temp2!=NULL){
        if(strcmp(temp2->var_name,var_name)==0)
            return 1;
        temp2 = temp2->next_item;
    }
    struct scope* temp=current_scope;
    while(temp->parent_scope!=NULL){
        temp=temp->parent_scope;
        temp2 = temp->var_items;
        while(temp2!=NULL){
            if(strcmp(temp2->var_name,var_name)==0)
                return 1;
            temp2 = temp2->next_item;
        }
    }
    return 0;
}*/

void print_table(struct scope* c, int k)
{
	if(c==NULL)
		return;

	printf("ID\tType\tValue\tLine\n");
	int i = 0;
	while(i!=k)
	{
		i++;
		printf("\t");
	}
	printf("---------\n");
	struct item_list* temp = c->var_items;
	while(temp!=NULL)
	{
		int i = 0;
		while(i!=k)
		{
			i++;
			printf("\t");
		}
		if(temp->var_type==int_type)
			printf("%s\t%d\t%d\t%d\n", temp->var_name, temp->var_type, (int)*((float*)temp->value), temp->line_num);
		if(temp->var_type==float_type)
			printf("%s\t%d\t%f\t%d\n", temp->var_name, temp->var_type, *((float*)temp->value), temp->line_num);
		if(temp->var_type==string_type || temp->var_type==list_type)
			printf("%s\t%d\t%s\t%d\n", temp->var_name, temp->var_type, (char*)temp->value, temp->line_num);
		if(temp->var_type==bool_type)
		{
			if((int)*((float*)temp->value)==1)
				printf("%s\t%d\t%s\t%d\n", temp->var_name, temp->var_type, "True", temp->line_num);
			if((int)*((float*)temp->value)==0)
				printf("%s\t%d\t%s\t%d\n", temp->var_name, temp->var_type, "False", temp->line_num);
		}
		temp = temp->next_item;
	}
	i = 0;
	while(i!=k)
	{
		i++;
		printf("\t");
	}
	printf("---------\n");
	print_table(c->child_scope, k+1);
	print_table(c->next_in_scope, k);
}
