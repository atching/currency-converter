/* EE 471 Winter 2014 Currency Converter
Alexander Ching, Kendrick Tang, Cameron Forbis

*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#define USD 1		// US Dollar
//#define EUR 1.36	// Euro
//#define YEN 0.0095	// Japanese Yen
//#define GBP 1.65	// British Pound
//#define CHF 1.10	// Swiss Franc
//#define AUD 0.89	// Australian Dollar
//#define CAD 0.92	// Canandian Dollar
//#define SEK 0.15	// Swedish Krona
//#define HKD 0.13	// Hong Kong Dollar
//#define NOK 0.16	// Norwegian Krone
//#define VND 0.000047 // Vietnamese Dong
//#define INR 0.016	// Indian Rupee

float valueConvert(char *currency);
float getData(void);
float toDollars(float foreignAmount, float exchangeRate);
float toForeign(float dollarAmount, float exchangeRate);
void displayResults(float value);

char currencyBase[4];
char currencyNew[4];
float conversion;

void main(){
	int i;
	float currency1 = 0.0;
	float currency2 = 0.0;
	char currencyBaseTemp[4];


	puts("Welcome to the Currency Converter");
	//puts("Supported currencies include: USD, EUR, YEN, GBP, CHF, AUD, CAD, SEK, HKD, NOK");

	puts("Please enter in base currency: ");
	scanf("%s", &currencyBase);

	for(i = 0; i < 3; i++){
		currencyBaseTemp[i] = tolower(currencyBase[i]);
	}

	puts("Please enter in currency you want to convert to: ");
	scanf("%s", &currencyNew);

	if(!strncmp(currencyNew, "usd", 4)){
		puts("Please enter in amount of USD: ");
		currency1 = getData();
		printf("Please enter in Exchange Rate to USD: ");
		conversion = getData();
		displayResults(toDollars(currency1, conversion));
	} else{
		printf("Please enter in amount of %s: ", currencyBase);
		currency1 = getData();
		printf("Please enter in Exchange Rate to %s: ", currencyNew);
		conversion = getData();
		displayResults(toForeign(currency1, conversion));
	}

	getchar();

	while(1);
}

//float valueConvert(char *currency){
//	int i = 0;
//
//	float a = 0;
//	for(i = 0; i < 3; i++){
//		currency[i] = tolower(currency[i]);
//	}
//
//	if(strncmp(currency, "usd", 4) == 0){
//		return USD;
//	}else if(strncmp(currency, "eur", 4) == 0){
//		return EUR;
//	}else if(strncmp(currency, "yen", 4) == 0){
//		return YEN;
//	}else if(strncmp(currency, "gbp", 4) == 0){
//		return GBP;
//	}else if(strncmp(currency, "chf", 4) == 0){
//		return CHF;
//	}else if(strncmp(currency, "aud", 4) == 0){
//		return AUD;
//	}else if(strncmp(currency, "cad", 4) == 0){
//		return CAD;
//	}else if(strncmp(currency, "sek", 4) == 0){
//		return SEK;
//	}else if(strncmp(currency, "hkd", 4) == 0){
//		return HKD;
//	}else if(strncmp(currency, "nok", 4) == 0){
//		return NOK;
//	}else if(strncmp(currency, "vnd", 4) == 0){
//		return VND;
//	}else if(strncmp(currency, "inr", 4) == 0){
//		return INR;
//	}
//
//}

float getData(void){
	float inputAmount = 0.0;
	scanf("%f", &inputAmount);

	return inputAmount;
}


/*
Enter the foreign amount and how many dollars 1 foreign unit is
equal to.
*/
float toDollars(float foreignAmount, float exchangeRate){
	return foreignAmount * exchangeRate;
}

/*
Enter the dollar amount and how many of foreign units 1 dollar is
equal to.
*/
float toForeign(float dollarAmount, float exchangeRate){
	return dollarAmount * exchangeRate;
}

/*
Enter the converted value
*/
void displayResults(float value){
	printf("The current conversion for %s to %s is %.2f\n", currencyBase, currencyNew, conversion);
	printf("The converted value is: %.2f\n", value);

}