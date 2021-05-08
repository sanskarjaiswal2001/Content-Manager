#include <bits/stdc++.h>

using namespace std;
int loop = 1;
string password = "rts";
vector<pair<string, string>> posts;

bool password_validator()
{
	string pass;
	int trials = 3;
	while (trials)
	{
		if (trials == 3)
		{
			cout << "\nEnter your password : ";
			getline(cin, pass);
			cout << endl;
		}
		if (trials != 3)
		{
			cout << "\033[1;31mYou've entered wrong password. Please try again. \033[0m";
			getline(cin, pass);
			cout << endl;
		}

		if (pass == password)
		{
			system("cls");
			return true;
			break;
		}
		trials--;
	}
	return false;
}

void addrecord()
{

	system("cls");
	string title;
	cout << "Enter the title here : ";
	getline(cin, title);

	cout << "\nEnter the content here " << endl;
	vector<string> str_vec;

	string str3 = "";

	string x;
	while (getline(cin, x))
	{
		if (x == "")
		{
			break;
		}

		else
		{
			str_vec.push_back(x);
		}
	}
	time_t now = time(0);
	char *dt = ctime(&now);
	str_vec.push_back("");
	str_vec.push_back((dt));	

	for (int i{}; i < str_vec.size(); i++)
	{
		str3 = str3 + str_vec[i] + "\n";
	}

	posts.push_back(make_pair(title, str3));

	cout << "\033[1;32mPost has been submitted.\033[0m\n";
}

void displayrecord()
{

	system("cls");

	if (posts.size() == 0)
	{

		cout << "\033[1;31mThere are no posts available.\033[0m\n";
		return;
	}
	else
	{
		for (int i{}; i < posts.size(); i++)
		{
			cout << "\033[4;33mPOST " << i + 1 << "\033[0m\n\n";
			cout << "\033[1;36m" << posts[i].first << "\033[0m\n\n";
			cout << "\033[1;37m" << posts[i].second << "\033[0m\n";
			cout << endl;
		}
	}
}

void editrecord()
{

	system("cls");
	cout << "Which post would you like to edit? ";
	string index;
	getline(cin, index);
	int idx = stoi(index);
	cout << "The post looks like this : \n"
		 << endl;
	cout << "\033[1;36m" << posts[idx - 1].first << "\033[0m\n\n";
	cout << "\033[1;37m" << posts[idx - 1].second << "\033[0m\n";
	cout << "What would you like to edit, the title or the content? \n";
	string edit;
	getline(cin, edit);
	if (edit == "title" || edit == "Title")
	{
		cout << "\nEnter the new Title : ";
		string title;
		getline(cin, title);
		posts[idx - 1].first = title;
	}

	if (edit == "content" || edit == "Content")
	{
		cout << "\nEnter the new content : \n";
		vector<string> str_vec;

		string str3 = "";

		string x;
		while (getline(cin, x))
		{
			if (x == "")
			{
				break;
			}

			else
			{
				str_vec.push_back(x);
			}
		}

		time_t now = time(0);
	    char *dt = ctime(&now);
	    str_vec.push_back("");
	    str_vec.push_back(dt);

		for (int i{}; i < str_vec.size(); i++)
		{

			str3 = str3 + str_vec[i] + "\n";
		}

		posts[idx - 1].second = str3;
	}
	cout << "\n"
		 << endl;

	cout << "\033[1;32mThe post has been edited.\033[0m\n\n";

	cout << "\033[1;36m" << posts[idx - 1].first << "\033[0m\n\n";
	
	cout << "\033[1;37m" << posts[idx - 1].second << "\033[0m\n";
}

void deleterecord()
{
	system("cls");
	cout << "Which post would you like to delete? ";
	string index;
	getline(cin, index);
	int idx = stoi(index);
	cout << endl;
	string confirm;
	cout << "\033[1;36m" << posts[idx - 1].first << "\033[0m\n\n";
	cout << "\033[1;37m" << posts[idx - 1].second << "\033[0m\n";
	cout << "Are you sure you'd like to delete the above post?(Yes/No): ";

	getline(cin, confirm);
	if (confirm == "Yes" || confirm == "yes")
	{

		posts.erase(posts.begin() + (idx - 1));
		cout << "\n\033[1;32mThe post has been deleted.\033[0m\n\n";
	}
	else
	{

		cout << "\n\033[1;32mThe post has not been deleted.\033[0m\n\n";
	}
}

int main()
{
	system("cls");
	string uname;
	cout << "Enter your username: ";
	getline(cin, uname);

	if (password_validator())
	{
 
		cout << "\t****************************************" << endl;
		cout << "  \t*                                    *\n";
		cout << "\t*   Welcome to your profile " << uname;
		cout << "  *\n";
		cout << "  \t*                                    *\n";
		cout << "\t****************************************" << endl;

		do
		{

			// Now here we have the code,

			cout << "\nPress 1 to add the record." << endl;
			cout << "Press 2 to display record." << endl;
			cout << "Press 3 to edit a record." << endl;
			cout << "Press 4 to delete any record." << endl;
			cout << "Press 5 to exit out of the program. \n" << endl;

			string choice;
			getline(cin, choice);
			if (choice == "1")
			{
				addrecord();
			}
			if (choice == "2")
			{
				displayrecord();
			}

			if (choice == "3")
			{
				editrecord();
			}

			if (choice == "4")
			{
				deleterecord();
			}

			if (choice == "5")
			{

				cout << "\n\033[1;34mThank You for using the program.\033[0m\n\n\n";
				exit(0);
			}
			if(choice!="1" && choice!="2" && choice!="3" && choice!="4" && choice!="5")
			 {cout<<"\n\nThat is not a valid choice. Please try again.\n \n";}

		} while (loop);
	}
	else
	{
		cout << "\033[1;31mYou have reached the maximum number of attempts. Please try again later.\033[0m\n\n";
		exit(1);
	}
}