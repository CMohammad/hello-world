#include <windows.h>
#include <stdio.h>
#include <conio.h>

void DrawColorString(char *szText,int X, int Y, WORD* color)
{
	COORD screenPos = {X,Y}; //THE POSITION STRUCT
	WORD  *colorBuf = NULL;  //THE COLOR BUFFER 
	
	DWORD dwResult = 0; 
	HANDLE	OutputH;
	
	int length = 0;
	int i = 0;
	
	if (szText == NULL)
		return ;
	
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	length = strlen(szText);
	
	colorBuf = (WORD*)malloc(sizeof(WORD) * length);
	
	for(i = 0; i < length ; i++){
		colorBuf[i] = color[i];
	}
	
	WriteConsoleOutputAttribute(OutputH, colorBuf, length, screenPos, &dwResult);
	WriteConsoleOutputCharacter(OutputH, szText  , length, screenPos, &dwResult);
	
	free(colorBuf);  // after every malloc we use free()
	colorBuf = NULL;
}


int main(){
	
	char *str = (char *)"0123456789ABCDE";  
	
	WORD colors[(int)strlen(str)];
	
	for(int i = 1; i < strlen(str); i++){
		colors[i] = i;
	}
	
	DrawColorString(str, 2,2, colors);
	
	while(!kbhit());
	
	return 0;
}
