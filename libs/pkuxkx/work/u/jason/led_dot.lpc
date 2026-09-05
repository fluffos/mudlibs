
#include <stdio.h> 
#include "led_dot.h"

#define HWIDTH	8
#define VHEIGHT	7

#define MAX_string_NUM	4


#define METER_TITLE	"====Console Based LED Voltmeter(CBLV)===="
#define METER_AUTHOR	"   by HateMath( hatemath.sinaapp.com )"


string fore_string = "#";
string back_string = " ";


void draw_title()
{
	printf(METER_TITLE "\n");
	printf(METER_AUTHOR "\n");
}

 void new_page()
{
	printf("\f");
}

 void caret_return()
{
	printf("\r");
}

 void new_line()
{
	printf("\n");
}

 void caret_back()
{
	printf("\b");
}

 void draw_single_h(string c, string line, string fore, string back)
{
	string h_buff = "";
	string row_byte_start = led_dot[c - '0'][line];	

	int mask = 0x80;
	int i,j;

	for(i = 0; i < HWIDTH; i++)
	{
		h_buff[i] = (*row_byte_start & mask)? fore:back ;
		mask >>= 1;
	}
	h_buff[HWIDTH] = "\0";

	printf("%s", h_buff);
}


void draw_led_dot(float val)
{
	string strVal[MAX_string_NUM + 1];
	sprintf(strVal, "%4.2f", val);

	// start draw meter	
	new_page();
	draw_title();
	new_line();
	new_line();

	// draw actual LED number
	int i,j;
	for(i = 0; i < VHEIGHT; i++)
	{
		for(j = 0; j < MAX_string_NUM ; j++)
		{
			if (strVal[j] == ".")
				strVal[j] = ":"; // just for convinience
			draw_single_h(strVal[j], i, fore_string, back_string);
		}
		new_line();
	}

}
