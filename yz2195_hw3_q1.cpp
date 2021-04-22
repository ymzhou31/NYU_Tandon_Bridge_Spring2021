#include <iostream>
using namespace std;

const float PROMOTION = .50;
const float CLUB_DISCOUNT = .90;

int main() {

	float item1, item2;
	float tax_rate, base_price;
	float promotion_price, discount_price, final_price;
	char clubCard;

	cout << "Enter price of first item:";
	cin >> item1;
	cout << "Enter price of second item:";
	cin >> item2;
	cout << "Does customer have a club card (Y/N):";
	cin >> clubCard;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax:";
	cin >> tax_rate;
	
	base_price = item1 + item2;

	if (item1 >= item2){
		promotion_price = item1 + PROMOTION * item2;
	}
	else{
		promotion_price = PROMOTION * item1 + item2;
	}

	if (clubCard == 'y' || clubCard == 'Y')	{
		discount_price = promotion_price * CLUB_DISCOUNT;
	}
	else if (clubCard == 'n' || clubCard == 'N')	{
		discount_price = promotion_price;
	}
	else{
		cout << "Not a valid input for club membership.";
		discount_price = promotion_price;
	}

	final_price = (1 + tax_rate/100) * discount_price;

	cout << "Base price:"<<base_price<<endl;
	cout << "Price after discounts:"<<discount_price<<endl;
	cout << "Total price:"<<final_price<<endl;

	return 0;
}