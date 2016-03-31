task main()
{
	char code[4] = {' ', ' ', ' ', '\0'};
	char scanned [4] = {'R', 'B', 'G', '\0'};
	char choice = 'R';
	int direction = 0;
	string question = "Give me a color";
	string wronganswer = "Color unrecognized";
	string answer1 = "I see color  ";
	string answer2 = "And that is number  ";
	string answer3 = "Which means I'm ";
	string case1 = "The robot is holding still";
	string case2 = "turning Left.";
	string case3 = "going straight.";
	string case4 = "turning right.";
	string case5 = "turning right.";
	string case6 = "turning Back.";
	string case7 = "Nothing happened?";

	displayString(3, "%s", question);

	if (choice != 'B' && choice != 'G' && choice != 'R')
	{
		displayString (4, "%s", wronganswer);
	}
	for (int i=0; i<sizeof(scanned); i++)
	{
		code[i] = scanned[i];
	}
	for(int i=0; i<sizeof(code); i++)
	{
		if(choice == code[i])
		{
			displayString(4, "%s ", answer1);
			displayString(4, "%d", code[i]);
			displayString(4, "%s ", answer2);
			displayString(4, "%d", i);
			direction = i + 1;
			displayString(5, "%s", answer3);
		}
	}

	switch (direction)
	{
	case 0:
		displayString(5, "%s", case1);
		break;
	case 1:
		displayString(5, "%s", case2);
		break;
	case 2:
		displayString(5, "%s", case3);
		break;
	case 3:
		displayString(5, "%s", case4);
		break;
	case 4:
		displayString(5, "%s", case5);
		break;
	default:
		displayString(5, "%s", case6);
		break;
	}

}
