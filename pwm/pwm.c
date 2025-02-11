#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_PIN 22 //pino conectado ao servo motor
const uint16_t WRAP_PERIOD = 19999; //valor máximo do contador - WRAP
const float PWM_DIVISER = 125.0; //divisor do clock para o PWM
const uint16_t incremento = 5; //passo de incremento/decremento para o duty cycle do LED
uint16_t nivel = 500; //nível inicial do pwm (duty cycle)

//função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_PIN); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap
    //// Define o duty cycle: 12% de 20ms -> 0.12 * 20000 = 2400 ticks
    pwm_set_gpio_level(PWM_PIN, 100); //definir o cico de trabalho (duty cycle) do pwm

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}

int main()
{
    stdio_init_all();
    pwm_setup(); //configurar o módulo PWM

    pwm_set_gpio_level(PWM_PIN, 2400); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_PIN, 1470); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_PIN, nivel); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);

    bool inc = false;
    while (true) {
    
        inc = true;

        if (inc == true)
        {
            while (nivel < 2400)
            {
                nivel += incremento;
                pwm_set_gpio_level(PWM_PIN, nivel); //definir o cico de trabalho (duty cycle) do pwm
                sleep_ms(10);
            }
            
            inc = false;
        }
        if (inc == false)
        {
            while (nivel > 500)
            {
            nivel -= incremento;
            pwm_set_gpio_level(PWM_PIN, nivel); //definir o cico de trabalho (duty cycle) do pwm
            sleep_ms(10);     
            }
            inc = true;   
        }
        
        }  
}