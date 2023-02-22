#define _CRT_SECURE_NO_WARNINGS // sprintf warnings

#include <stdio.h> // input - output
#include <stdlib.h>
#include <conio.h> // _getche()


int main()
{
	char map[20][41];
	int i;
	int dogX = 10, dogY = 5; // Dog's coordinates on a map
	char key; // Keyboard pressed char  
	int dogXbeforeMovement;
	int dogYbeforeMovement;
	int appleX = 5, appleY = 4; // Apple coordinates on a map
	int appleCount = 0;

	srand(time(NULL));

	do
	{
		// MAP
		sprintf(map[0], "#######################################");
		for (i = 1; i < 19; i++)
		{
			sprintf(map[i], "#                                     #");
		}
		sprintf(map[19], "#######################################");
		//

		// Dog, apple creation
		map[dogY][dogX] = (char)64;
		map[appleY][appleX] = (char)42;
		//
		

		// system clear
		system("cls");
		//

		for (i = 0; i < 20; i++)
		{
			printf("%s\n", map[i]);
		}

		printf("Controls:\n w - up\n s - down\n a - left\n d - right\t e - exit the game\n\n");
		printf("Apples = %d\n", appleCount);

		// Dog's movement
		key = _getche();

		dogXbeforeMovement = dogX;
		dogYbeforeMovement = dogY;

		if (key == 'w') dogY--;
		if (key == 's') dogY++;
		if (key == 'a') dogX--;
		if (key == 'd') dogX++;

		if (map[dogY][dogX] == '#')
		{
			dogX = dogXbeforeMovement;
			dogY = dogYbeforeMovement;
		}
		//

		if ((dogX == appleX) && (dogY == appleY))
		{
			appleX = rand() * 1.0 / RAND_MAX * 38;
			appleY = rand() * 1.0 / RAND_MAX * 18 + 1;
			appleCount++;
		}
	} while (key != 'e');

	return 0;
}