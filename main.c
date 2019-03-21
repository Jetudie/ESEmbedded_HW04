#include "blink.h"

int main(void)
{
	while(!button_pushed(PUSH_BUTTON_USER_B1))
		;
	
	blink(LED_BLUE);
}
