/**
 Function to get multiple-worded string
**/
void
getPhrase(char* s)
{
	char ch;
	int i = 0;

	do
	{
		scanf("%c", &ch);
		if (ch != '\n')
		{ 
			s[i] = ch;
			i++;
			s[i] = '\0';
		}
	}while (ch != '\n' || i == 0); 
}

/**
 Function to store initial values to directory list
**/
void
populate(directoryType* dList)
{
	int i, j;
	for(i=0; i<MAX; i++){
		getPhrase(dList[i].category);
		scanf("%d", &(dList+i)->count);
		for(j=0; j<(dList+i)->count; j++){
			getPhrase(dList[i].b[j].name);		
			getPhrase((dList+i)->b[j].address);
			scanf("%ld", &(dList+i)->b[j].number);
		}
	}
}

/**
 Function to display values of all members of the directory list
**/
void
displayDirectory(directoryType dList[])
{
	int i, j, len;
	printf("%s%s%s DIRECTORY %s%s%s\n", "===============", "===============", "===============",
			"===============", "===============", "===============");
	printf("   %-40s%-30s%-11s\n", "Business Name", "Address", "Number");
	printf("%s%s%s%s%s%s%s\n", "---------------", "---------------", "---------------",
			"---------------", "---------------", "---------------", "-----------");
	for(i=0; i<MAX; i++){
		printf("----- %s", dList[i].category);
		for(len=20-strlen(dList[i].category); len>0; len--)
			printf("-");
		printf("%s%s%s%s%s\n", "---------------", "---------------",
			"---------------", "---------------", "---------------");
		if(dList[i].count > 0){
			for(j=0; j<dList[i].count; j++){
				printf("%2d %-40s%-30s0%ld\n", j+1,
					dList[i].b[j].name,
					dList[i].b[j].address,
					dList[i].b[j].number);
			}
		}
		else
			printf("Empty...\n");
	}
	printf("%s%s%s%s%s%s%s\n", "===============", "===============", "===============",
			"===============", "===============", "===============", "===========");
}

/**
 Function to display as task indicator and separator
**/
void
displayTask(int count, String30 task){
int len;
	printf("\n** TASK #%d: %s() ", count, task);
	for(len=28-strlen(task); len>0; len--)
		printf("*");
	printf("%s%s%s%s\n", "**************", "**************",
			"***************", "***************");
}
