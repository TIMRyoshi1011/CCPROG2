#define MAX 5 // used as maximum number of directories AND businesses per category
typedef char String30[31];
typedef char String40[41];

/**
 structure for a business
 a business has name, address, and number
 */
struct businessTag
{
  String40 name;
  String30 address;
  long int number;
};
typedef struct businessTag businessType;

/**
 structure for a directory
 a directory has a category, count of businesses, and list of businesses b
 */
struct directoryTag
{
  String30 category;
  int count;
  businessType b[MAX];
};
typedef struct directoryTag directoryType;

/******************************************************************************
 Below are the function prototypes of the functions you need to
 implement in the file YellowPages-LASTNAME.c
 
 You are NOT allowed to modify/change the return type nor parameters.
*******************************************************************************/
 
int getCategory(directoryType dList[], String30 category);
int addBusiness(String30 category, directoryType dList[], businessType newBusiness);
businessType getBusinessInfo(directoryType dList[], String40 businessName);
businessType findBusinessInCityCategory(String30 city, directoryType specificCategory);
void sortCatBusiness(directoryType dList[], directoryType sortedList[]);
