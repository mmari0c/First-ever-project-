/*	
	Name: Mario Nolasco 
	EUID: mdn0088
	E-mail address: MarioNolascoCortez@my.unt.edu
	Department name: Computer Programming 1 (CSCE)
	Coutrse number: 1030.304-306
*/
/*	
	Name: Anthony Dobis
	EUID: ad1182
	E-mail address: TonyDobis@my.unt.edu
	Department name: Computer Programming 1 (CSCE)
	Coutrse number: 1030.304-306
*/

#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
using namespace std;

enum menuChoices {displayLeft = 1, displayRight = 2, Guess = 3, Change = 4, Exit = 5};

int main()
{
	string userName;
	int numPoints = 100;
	int randNum1;
	int randNum2;
	int randPlace1 = -1; //Placeholder for rand number, gets displayed if user wants to see it 
	int randPlace2 = -1; 
	int userInput;
	int userGuess;
	bool numDisplayed = false; //Bool variable that determines if user has displayed a random number

	cout << "+---------------------------------------------------+" << endl;
	cout << "|" << "          " << "Computer Science and Engineering" << "         " << "|" << endl;
	cout << "|" << "          " << "CSCE 1030 - Computer Science I" << "           " << "|" << endl;
	cout << "|" << "" << "Mario Nolasco mdn0088 MarioNolascoCortez@my.unt.edu" << "" << "|" << endl;
	cout << "+---------------------------------------------------+" << endl;

	cout << "+---------------------------------------------------+" << endl;
	cout << "|" << "          " << "Computer Science and Engineering" << "         " << "|" << endl;
	cout << "|" << "          " << "CSCE 1030 - Computer Science I" << "           " << "|" << endl;
	cout << "|" << "      " << "Anthony Dobis ad1182 TonyDobis@my.unt.edu" << "    " << "|" << endl;
	cout << "+---------------------------------------------------+" << endl;
	
	cout << "Enter name of player: ";
	getline(cin, userName);
	
	for(int i = 0; i < userName.length(); i++)
	{	
		
		if(!(isalpha(userName.at(i))) && (!(isspace(userName.at(i))))) //Checks if characters in the username aren't letter and spaces
		{	
			cout << "Error, your name can only have alphabets or space." << endl;
			cout << "Please enter name of player again: ";
			getline(cin, userName);	
			i = 0;
		}
	
	}

	userName.at(0) = toupper(userName.at(0)); //Turns first character into an uppercase

	for(int i = 1; i < userName.length(); i++) 
	{ 
		if(isspace(userName.at(i - 1))) //Converts every initial into uppercase
		{		
			userName.at(i) = toupper(userName.at(i)); 
		}
		else //Converts every other into lowercase
		{
			userName.at(i) = tolower(userName.at(i));
		}		
	}
	
	srand(time(0)); //Creates two randomly generated numbers
	randNum1 = rand() % 101 + 100;
	randNum2 = rand() % 101 + 100;

	while(randNum1 > randNum2) //Loop that keeps generating numbers into randNum1 is less than randNum2
	{
		randNum1 = rand() % 101 + 100;
		randNum2 = rand() % 101 + 100;
	}

	
	cout << randPlace1 << "\t" << randPlace2 << endl;
	cout << "1. Display Left Number" << endl << "2. Display Right Number" << endl << "3. Guess a number in between" << endl << "4. Change numbers" << endl << "5. Exit" << endl << "What do you want to do? ";
	cin >> userInput;
	
	while (userInput != Exit) //Program runs until the user decides to exit
	{
		switch(userInput) 
		{ 
			case displayLeft: 
			
				if(numDisplayed) //Output if user already displayed randNum2
				{
					cout << "Thought it'll be that easy? You have already displayed the right boundry." << endl;
				}
				else //Displays the left randomly generated number 
				{
					cout << "A correct guess will only earn you 1 point, and an incorrect guess will lose you 10 points in the game" << endl;
					randPlace1 = randNum1;	
					numDisplayed = true;
				} 
			break;
				
			case displayRight: 	

				if(numDisplayed) //Output if user already displayed randNum1
				{
					cout << "Thought it'll be that easy? You have already displayed the left boundry." << endl;
				}
				else //Displays the right generated number if no number has been displayed
				{
					cout << "A correct guess will only earn you 1 point, and an incorrect guess will lose you 10 points in the game" << endl;
					randPlace2 = randNum2;
					numDisplayed = true;
				}
			break;
					
			case Guess:

				cout << "Go ahead, enter your guess: ";
				cin >> userGuess;
				
				if (!numDisplayed) //Point system if user hasn't choose to display either boundry
				{
					if ((userGuess > randNum1) && (userGuess < randNum2)) 
					{
				
						cout << "Congrats! You've earned 5 points" << endl;
						numPoints += 5;
						cout << "You have " << numPoints << " points" << endl;
					}			
					else 
					{
	
						cout << "Sorry, you've lost 5 points" << endl;
						numPoints -= 5;
						cout << "You have " << numPoints << " points" << endl;
					}
				}
				
				else if (numDisplayed) //Point system if user decides to display one of the boundaries 
				{
					if ((userGuess > randNum1) && (userGuess < randNum2))
					{
						
						cout << "Congrats! You've earned 1 points" << endl;
						numPoints += 1;
						cout << "You have " << numPoints << " points" << endl;
					}			
					else 
					{
						cout << "Sorry, you've lost 10 points" << endl;
						numPoints -= 10;
						cout << "You have " << numPoints << " points" << endl;
					}
				}
				break;
			
			case Change: //Changes the randomly generated number until randNum1 is less than randNum2

				cout << "Generating new boundaries." << endl;
				randNum1 = rand() % 101 + 100;
				while(randNum1 > randNum2)
					{
						randNum1 = rand() % 101 + 100;
						randNum2 = rand() % 101 + 100;
					}

				randPlace1 = -1;
				randPlace2 = -1;
				numDisplayed = false;
				numPoints -= 1;

				cout << "You have " << numPoints << " points" << endl;
		}

		if(numPoints < 0) //Checks if user has less than 0 points to stop the loop
		{ 
			cout << "Unfortunately, you are out of points." << endl;
			break;
		}
		else 
		{
		cout << randPlace1 << "\t" << randPlace2 << endl;
		cout << "1. Display Left Number" << endl << "2. Display Right Number" << endl << "3. Guess a number in between" << endl << "4. Change numbers" << endl << "5. Exit" << endl << "What do you want to do? ";
		cin >> userInput;
		}

	}
	
	cout << "Thanks for playing! Goodbye " << userName << "!" << endl;
	cout << "Your final points balance = " << numPoints << endl;

return 0;
}