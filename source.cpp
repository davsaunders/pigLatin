#include <iostream>
#include <string>

using namespace std;

bool checkVowel(const string);

int main()
{

	string user, temp, translated = "";
	int index = 0, position, length;

	cout << "Enter a phrase to be translated: ";
	getline(cin, user);

	length = user.length();

	while (user.back() == ' ')
	{
		user.erase(length - 1, 1);
	}

	user = user + ' ';
	do
	{
		position = user.find(' ', 0);
		temp = user.substr(0, position);
		if (checkVowel(temp))
			temp = temp + "way";
		else
		{
			temp = temp + temp[0] + "ay";
			temp.erase(0, 1);
		}
		if (translated.empty())
			translated = temp;
		else
			translated = translated + ' ' + temp;
		user = user.substr(position + 1, string::npos);
	} while (user.find(' ', index) != user.length()-1);

	position = user.find(' ', index);
	user.erase(position, 1);
	if (checkVowel(user))
		user = user + "way";
	else
	{
		user = user + user[0] + "ay";
		user.erase(0, 1);
	}

	translated = translated + ' ' + user;
	cout << translated << endl;

	return 0;
}

bool checkVowel(const string str)
{
	if (str[0] == 'a' || str[0] == 'e' || str[0] == 'i'
		|| str[0] == 'o' || str[0] == 'u')
		return true;
	else
		return false;
}
