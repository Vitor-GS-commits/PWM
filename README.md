
# Controle de Servomotor e LED RGB com PWM no Raspberry Pi Pico W

## Descrição do Projeto

Este projeto demonstra o controle de um **servomotor** e de um **LED RGB** utilizando a modulação por largura de pulso (**PWM**) no **Raspberry Pi Pico W**. Variando o ciclo ativo do PWM, controlamos o ângulo do servomotor e a intensidade luminosa do LED, explorando conceitos fundamentais de sistemas embarcados.

## Componentes Utilizados

- **Microcontrolador**: Raspberry Pi Pico W  
- **Servomotor**: Micro servo padrão (simulado no Wokwi)  
- **LED RGB**: Conectado ao **GPIO 12**  
- **Simulador**: Wokwi (integrado ao VS Code)  

## Funcionalidades Implementadas

### 1. Controle do Servomotor (GPIO 22)

- **Frequência do PWM**: **50Hz** (período de 20ms)  
- **Posições do Servo**:
  - **180 graus**: Ciclo ativo de **2400µs** (Duty Cycle de 12%)
    - Aguarda **5 segundos**
  - **90 graus**: Ciclo ativo de **1470µs** (Duty Cycle de ~7.35%)
    - Aguarda **5 segundos**
  - **0 graus**: Ciclo ativo de **500µs** (Duty Cycle de 2.5%)
    - Aguarda **5 segundos**
- **Movimentação Suave**:
  - Incremento/Decremento de **±5µs**
  - Atraso de **10ms** entre cada passo
  - Movimenta o servo gradualmente entre 0 e 180 graus

### 2. Controle do LED RGB (GPIO 12)

- **Observação**: O LED apresenta uma **variação na luminosidade**, aumentando e diminuindo gradativamente.
- **Comportamento Observado**: Essa variação suave demonstra o controle da intensidade luminosa usando PWM.

## Como Executar o Projeto

### 1. Clonar o Repositório

```bash
git clone <URL-do-repositório>
````

### 2. Abrir o Projeto no VS Code

1. Instale a extensão **Raspberry Pi Pico Project** no VS Code.
2. Certifique-se de que o **Pico SDK** está configurado corretamente.
3. Abra o projeto no **VS Code**.

### 3. Compilar e Carregar o Código

1. No VS Code, vá até a extensão raspberry pi pico project e selecione:
   ```bash
   Compile Project
   ```
2. Para carregar o código no Pico W, selecione:
   ```bash
   Run Project(USB)
   ```

### 4. Executar a Simulação no Wokwi

```bash
# Inicie a simulação e verifique as conexões:
# GPIO 22: Servomotor  
# GPIO 12: LED RGB  
```

### 5. Observar o Funcionamento

```bash
# Servomotor: Deve mover-se entre 0°, 90° e 180°, seguido de movimentação suave contínua.
# LED RGB: Deve apresentar variação gradual na luminosidade.
```

## Código Fonte

```plaintext
- Código do PWM: pwm.c
- Código do LED RGB: pwm_led.c

# Os arquivos de código estão incluídos no repositório.
```

## Observações

```bash
# Comportamento do LED: Observou-se uma variação na luminosidade do LED, aumentando e diminuindo gradativamente.
# Isso ocorre devido à alteração do ciclo ativo do PWM, controlando a intensidade luminosa.
# Movimento Suave do Servo: A alteração incremental do ciclo ativo permite que o servo mova-se de forma fluida entre os ângulos, simulando um movimento natural.
```

## Vídeo Demonstrativo

```plaintext
- Link do Vídeo: [Demonstração do Projeto ](https://drive.google.com/file/d/1xfnBOhzBqg78iXBLmlHP3vmtSrDLGukA/view?usp=sharing) 
```

## Considerações Finais

```bash
# Este projeto ilustra como o PWM pode ser utilizado para controlar dispositivos em sistemas embarcados:
# Servomotor: Controle preciso de posição, essencial em robótica e automação.
# LED RGB: Controle da intensidade luminosa, importante em aplicações visuais.
```

## Referências

```plaintext
- Pico SDK Documentation: https://raspberrypi.github.io/pico-sdk-doxygen  
- Wokwi Simulator: https://wokwi.com  

# Nota: Para dúvidas ou sugestões, sinta-se à vontade para entrar em contato ou abrir uma issue no repositório.
```

```
```
