#ifndef SAHDOLIB_H_INCLUDED
#define SAHDOLIB_H_INCLUDED

#include <string.h>

#define BLACK 	       1
#define RED 	       2
#define GREEN 	       3
#define YELLOW         4
#define BLUE           5
#define PINK           6
#define CYAN           7
#define WHITE          8

#define	NORMAL         1
#define	BOLD           2
#define	UNDERLINED     3
#define	BLINK          4
#define	REVERSE        5
#define	INVISIBLE      6


//Protótipos
void nicePrint(char string[50], int x, int y);
void gotoxy(int x, int y);
void clrscr();
void setTextMode(int mode);
void setColor(int text, int background);


//------------------------------------------------------------------------------
void nicePrint(char string[50], int x, int y)
{
   int i = 0;

   while(i < strlen(string))
   {
	switch(string[i])
	{
	   case 'A':
	   	//Monta o A
	   	gotoxy(x,y++);
	   	printf("*****");
	   	gotoxy(x,y++);
	   	printf("*   *");
	  	gotoxy(x,y++);
	   	printf("*****");
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	//Fim monta o A

	   	x = x+6;
	   	y = y-5;
		break;

	   case 'B':
	   	//Monta o B
	   	gotoxy(x,y++);
	   	printf("****");
	   	gotoxy(x,y++);
	   	printf("*   *");
	  	gotoxy(x,y++);
	   	printf("****");
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("****");
	   	//Fim monta o B

	   	x = x+6;
	   	y = y-5;
		break;

	   case 'C':
	   	//Monta o C
	   	gotoxy(x,y++);
	   	printf(" ****");
	   	gotoxy(x,y++);
	   	printf("*   *");
	  	gotoxy(x,y++);
	   	printf("*    ");
	   	gotoxy(x,y++);
	   	printf("*    ");
	   	gotoxy(x,y++);
	   	printf(" ****");
	   	//Fim monta o C

	   	x = x+6;
	   	y = y-5;
		break;

	    case 'D':
	   	//Monta o D
	   	gotoxy(x,y++);
	   	printf("****");
	   	gotoxy(x,y++);
	   	printf("*   *");
	  	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("**** ");
	   	//Fim monta o D

	   	x = x+6;
	   	y = y-5;
		break;

	    case 'E':
	   	//Monta o E
	   	gotoxy(x,y++);
	   	printf("*****");
	   	gotoxy(x,y++);
	   	printf("*    ");
	  	gotoxy(x,y++);
	   	printf("*****");
	   	gotoxy(x,y++);
	   	printf("*    ");
	   	gotoxy(x,y++);
	   	printf("*****");
	   	//Fim monta o E

	   	x = x+6;
	   	y = y-5;
		break;

	    case 'F':
	   	//Monta o F
	   	gotoxy(x,y++);
	   	printf("*****");
	   	gotoxy(x,y++);
	   	printf("*    ");
	  	gotoxy(x,y++);
	   	printf("*****");
	   	gotoxy(x,y++);
	   	printf("*    ");
	   	gotoxy(x,y++);
	   	printf("*    ");
	   	//Fim monta o F

	   	x = x+6;
	   	y = y-5;
		break;

	     case 'S':
	   	//Monta o S
	   	gotoxy(x,y++);
	   	printf(" ****");
	   	gotoxy(x,y++);
	   	printf("*    ");
	  	gotoxy(x,y++);
	   	printf(" ***");
	   	gotoxy(x,y++);
	   	printf("    *");
	   	gotoxy(x,y++);
	   	printf("**** ");
	   	//Fim monta o S

	   	x = x+6;
	   	y = y-5;
		break;

	   case 'K':
	   	//Monta o K
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("*  * ");
	  	gotoxy(x,y++);
	   	printf("***");
	   	gotoxy(x,y++);
	   	printf("*  *  ");
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	//Fim monta o K

	   	x = x+6;
	   	y = y-5;
		break;

	   case 'O':
	   	//Monta o O
	   	gotoxy(x,y++);
	   	printf(" *** ");
	   	gotoxy(x,y++);
	   	printf("*   *");
	  	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf(" *** ");
	   	//Fim monta o O

	   	x = x+6;
	   	y = y-5;
		break;

	   case 'U':
	   	//Monta o U
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("*   *");
	  	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf("*   *");
	   	gotoxy(x,y++);
	   	printf(" *** ");
	   	//Fim monta o U

	   	x = x+6;
	   	y = y-5;
		break;

	    default:
		printf("erro");
	}

	i++;
    }

    printf("\n\n");
}

//------------------------------------------------------------------------------
void gotoxy(int x, int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

//------------------------------------------------------------------------------
void clrscr()
{
    printf("\n");
    system("clear");
}

//------------------------------------------------------------------------------
void setTextMode(int mode)
{
	switch(mode)
	{
		//Normal
		case 1: printf("\033[0m"); break;
		//Bold
		case 2: printf("\033[1m"); break;
		//Underline
		case 3: printf("\033[4m"); break;
		//Blink
		case 4: printf("\033[5m"); break;
		//reverse
		case 5: printf("\033[7m"); break;
		//invisible
		case 6: printf("\033[8m"); break;
	}
}

//------------------------------------------------------------------------------
void setColor(int text, int background)
{
    switch(text)
    {

        //BLACK
	case 1:
		switch(background)
		{
 	 		//BLACK
			case 1: printf("\033[40;30m"); break;
        		//RED
			case 2: printf("\033[41;30m"); break;
			//GREEN
			case 3: printf("\033[42;30m"); break;
			//YELLOW
			case 4: printf("\033[43;30m"); break;
			//BLUE
			case 5: printf("\033[44;30m"); break;
			//MANGENTA
			case 6: printf("\033[45;30m"); break;
			//CYAN
			case 7: printf("\033[46;30m"); break;
			//WHITE
			case 8: printf("\033[47;30m"); break;
		}break;
        //RED
        case 2:
		switch(background)
		{
			//BLACK
			case 1: printf("\033[40;31m"); break;
        		//RED
			case 2: printf("\033[41;31m"); break;
			//GREEN
			case 3: printf("\033[42;31m"); break;
			//YELLOW
			case 4: printf("\033[43;31m"); break;
			//BLUE
			case 5: printf("\033[44;31m"); break;
			//MANGENTA
			case 6: printf("\033[45;31m"); break;
			//CYAN
			case 7: printf("\033[46;31m"); break;
			//WHITE
			case 8: printf("\033[47;31m"); break;
		}break;

        //GREEN
        case 3:
		switch(background)
		{
			//BLACK
			case 1: printf("\033[40;32m"); break;
        		//RED
			case 2: printf("\033[41;32m"); break;
			//GREEN
			case 3: printf("\033[42;32m"); break;
			//YELLOW
			case 4: printf("\033[43;32m"); break;
			//BLUE
			case 5: printf("\033[44;32m"); break;
			//MANGENTA
			case 6: printf("\033[45;32m"); break;
			//CYAN
			case 7: printf("\033[46;32m"); break;
			//WHITE
			case 8: printf("\033[47;32m"); break;
		}break;
        //YELLOW
        case 4:
		switch(background)
		{
			//BLACK
			case 1: printf("\033[40;33m"); break;
        		//RED
			case 2: printf("\033[41;33m"); break;
			//GREEN
			case 3: printf("\033[42;33m"); break;
			//YELLOW
			case 4: printf("\033[43;33m"); break;
			//BLUE
			case 5: printf("\033[44;33m"); break;
			//MANGENTA
			case 6: printf("\033[45;33m"); break;
			//CYA
			case 7: printf("\033[46;33m"); break;
			//WHITE
			case 8: printf("\033[47;33m"); break;
		}break;
        //BLUE
        case 5:
		switch(background)
		{
			//BLACK
			case 1: printf("\033[40;34m"); break;
        		//RED
			case 2: printf("\033[41;34m"); break;
			//GREEN
			case 3: printf("\033[42;34m"); break;
			//YELLOW
			case 4: printf("\033[43;34m"); break;
			//BLUE
			case 5: printf("\033[44;34m"); break;
			//MANGENTA
			case 6: printf("\033[45;34m"); break;
			//CYAN
			case 7: printf("\033[46;34m"); break;
			//WHITE
			case 8: printf("\033[47;34m"); break;
		}break;
        //MANGENTA
        case 6:
		switch(background)
		{
			//BLACK
			case 1: printf("\033[40;35m"); break;
        		//RED
			case 2: printf("\033[41;35m"); break;
			//GREEN
			case 3: printf("\033[42;35m"); break;
			//YELLOW
			case 4: printf("\033[43;35m"); break;
			//BLUE
			case 5: printf("\033[44;35m"); break;
			//MANGENTA
			case 6: printf("\033[45;35m"); break;
			//CYAN
			case 7: printf("\033[46;35m"); break;
			//WHITE
			case 8: printf("\033[47;35m"); break;
		}break;
        //CYAN
        case 7:
		switch(background)
		{
			//BLACK
			case 1: printf("\033[40;36m"); break;
        		//RED
			case 2: printf("\033[41;36m"); break;
			//GREEN
			case 3: printf("\033[42;36m"); break;
			//YELLOW
			case 4: printf("\033[43;36m"); break;
			//BLUE
			case 5: printf("\033[44;36m"); break;
			//MANGENTA
			case 6: printf("\033[45;36m"); break;
			//CYAN
			case 7: printf("\033[46;36m"); break;
			//WHITE
			case 8: printf("\033[47;36m"); break;
		}break;
        //WHITE
        case 8:
		switch(background)
		{
			//BLACK
			case 1: printf("\033[40;37m"); break;
        		//RED
			case 2: printf("\033[41;37m"); break;
			//GREEN
			case 3: printf("\033[42;37m"); break;
			//YELLOW
			case 4: printf("\033[43;37m"); break;
			//BLUE
			case 5: printf("\033[44;37m"); break;
			//MANGENTA
			case 6: printf("\033[45;37m"); break;
			//CYAN
			case 7: printf("\033[46;37m"); break;
			//WHITE
			case 8: printf("\033[47;37m"); break;
		}break;

	//Nenhum
 	default: printf("\n\ncor nao existe\n\n");
     }
}


#endif // SAHDOLIB_H_INCLUDED
