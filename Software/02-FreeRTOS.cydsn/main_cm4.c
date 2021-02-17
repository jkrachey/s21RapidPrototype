/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "main.h"

QueueHandle_t Queue_LEDs;


void Task_SW2(void)
{
   uint8_t button_state = 0xFF;
   uint32_t led_msg = 0x00;
   uint32_t button_value = 0;
    
    while(1)
    {  
        // Check the Button every 20 MS  -- ADD CODE
  
        
        // Debounce the pushbutton on the falling edge -- ADD CODE
        
        // If button pressed, send a message to the LED task. -- ADD CODE
    }
}

void Task_LEDs(void)
{
    uint32_t led_msg = 0x00;
    
    while(1)
    {
        // Wait until we receive a message -- ADD CODE
        
        
        if(led_msg == 0x00)
        {
            // Turn Green ON -- ADD CODE
            
            
            // Turn Red Off -- ADD CODE
        }
        else if (led_msg == 0x01)
        {
            // Turn Red ON -- ADD CODE
           
            
            // Turn Green Off -- ADD CODE  
        }
        else
        {
            // undefined
        }
    }
    
}


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CLI_Start();
    setvbuf(stdin,NULL,_IONBF,0);
    
    printf("\n\r");
    printf("***************************************\n\r");
    printf(" ECE453\n\r");
    printf("***************************************\n\r");    
    
    // Create the queue to send messages  -- ADD CODE
    
    // Create the tasks -- ADD CODE
    
    // Start the Scheduler
    vTaskStartScheduler();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
