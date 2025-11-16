#include <stdio.h>
#include <string.h>

#define MAX_SELLERS 100
#define MAX_PRODUCTS 5000

typedef char String30[31];

typedef struct {
	String30 first;
	String30 last;
}fullname;

struct sellerTag{
	int id;
	fullname name;
	float rating;
};

struct productTag {
	int id;
	String30 product_type;
	float price;
};

void InputSellers(struct sellerTag *SELLERS, int n_sellers) {
    int i;

    for(i = 0; i < n_sellers; i++) {
        printf("ID: ");
        scanf("%d", &SELLERS->id);

        printf("Name (first, last): ");
        scanf("%s", SELLERS->name.first);
        scanf("%s", SELLERS->name.last);

        printf("Rating: ");
        scanf("%f", &SELLERS->rating);
    }    
}

void InputProducts(struct productTag *PRODUCTS, int *n_products) {
	int i;

    for(i = 0; i < n_products; i++) {
        printf("ID: ");
        scanf("%d", &PRODUCTS->id);

        printf("Product Type: ");
        scanf("%s", PRODUCTS->product_type);

        printf("Price: ");
        scanf("%f", &PRODUCTS->price);
    }    
}

void Linear_Search (struct sellerTag SELLERS[], int n_sellers, int key) {
	int i;

    for(i = 0; i < n_sellers; i++)
        if(key == SELLERS->id)
            return i;

    return -1;
}

int main() {

    struct sellerTag SELLERS[MAX_SELLERS];      // MAX_SELLERS is defined in buysell.h
    struct productTag PRODUCTS[MAX_PRODUCTS];   // MAX_PRODUCTS is defined buysell.h
    
    int n_sellers;   // actual number of sellers
    int n_products;  // actual number of products
	 
	scanf("%d", &n_sellers);    // assume input is valid    
	scanf("%d", &n_products);   // assume input is value
		
	// sample InputSellers() function call
	InputSellers(SELLERS, n_sellers);

    // sample InputProducts() function
	InputProducts(PRODUCTS, n_products);

    return 0;
}