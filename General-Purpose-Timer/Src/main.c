#include "gpio.h"
#include "tim.h"

int main(void){

	led_init();
	tim2_1hz_init(); // TIMER HAS STARTED
	while(1){
		led_toggle();
		// wait for uif
		while(!(TIM2->SR & SR_UIF)){} // WAITING FOR THE TIMER TO GET COMPLETED
			TIM2->SR &=~SR_UIF;

	}


}


// Once tim2_1hz_init() sets CEN (counter enable bit) to 1,
//the hardware counter just keeps counting, tick after tick, forever —
// with zero involvement from your main() code:


// UIF — just a notification flag, not a control switch

//When that overflow happens, hardware also sets UIF = 1 as a side effect — think of it like a mailbox flag popping up: "hey, an overflow just happened, in case anyone's watching."
//
//Setting UIF = 1 → done automatically by hardware, at the exact moment of overflow.
//Clearing UIF = 0 → done manually by you, in software, whenever you're ready to acknowledge it.
