#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" // PWM library

#define PWM_LED 12 //pino do LED
const uint16_t WRAP_PERIOD = 19999; //valor máximo do contador - WRAP
const float PWM_DIVISER = 125.0; //divisor do clock para o PWM
const uint16_t incremento = 5; //passo de incremento/decremento para o duty cycle do LED
uint16_t nivel = 500; //nível inicial do pwm (duty cycle)

//função para configurar o módulo PWM
void pwm_setup()
{
    //configuração do pino do LED
    gpio_set_function(PWM_LED, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_LED); //obter o canal PWM da GPIO
    //configuração do divisor do clock
    pwm_set_clkdiv(slice, PWM_DIVISER);
    //configuração do contador
    pwm_set_wrap(slice, WRAP_PERIOD);
    //configuração do duty cycle
    pwm_set_gpio_level(PWM_LED, 100);
    //configuração do modo de saída
    pwm_set_enabled(slice, true);
}

int main()
{
    stdio_init_all();
    pwm_setup();

    pwm_set_gpio_level(PWM_LED, 2400); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_LED, 1470); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_LED, nivel); //definir o cico de trabalho (duty cycle) do pwm
    sleep_ms(5000);

    bool inc = false;

    while (true) {
        inc = true;

        if (inc == true)
        {
            while (nivel < 2400)
            {
                nivel += incremento;
                pwm_set_gpio_level(PWM_LED, nivel); //definir o cico de trabalho (duty cycle) do pwm
                float porcentagem = (nivel/2400.0)*100.0;
                printf("Nível porcentagem = %.2f\n", porcentagem); //imprimir o nível do pwm em porcentagem
                sleep_ms(10);
            }
            
            inc = false;
        }
        if (inc == false)
        {
            while (nivel > 500)
            {
                nivel -= incremento;
                pwm_set_gpio_level(PWM_LED, nivel); //definir o cico de trabalho (duty cycle) do pwm
                float porcentagem = (nivel/2400.0)*100.0;
                printf("Nível porcentagem = %.2f\n", porcentagem); //imprimir o nível do pwm em porcentagem
                sleep_ms(10);     
            }
            inc = true;   
        }
    }
}
