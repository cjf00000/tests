#include "addressbook.pb.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void SetPerson(tutorial::Person* person) {
	person->set_id(123);
	person->set_email("cjf00000@gmail.com");
	person->set_name("Chris Chen");

	tutorial::Person::PhoneNumber* phone_number = person->add_phone();
	phone_number->set_number("15201523695");
	phone_number->set_type(tutorial::Person::HOME);
}

int main()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	tutorial::AddressBook book;
	ifstream fin("address");
	book.ParseFromIstream(&fin);

	cout << book.DebugString() << endl;
	

	return 0;
}
