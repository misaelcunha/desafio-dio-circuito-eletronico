// Declaração de variáveis
int temperatura = 0;  // Armazena a temperatura calculada
int sensor = 0;       // Armazena o valor lido do sensor analógico
int led = 3;          // Pino digital conectado ao LED vermelho
int buzina = 2;       // Pino digital conectado à buzina
int motor = 4;        // Pino digital conectado ao motor

void setup()
{
  Serial.begin(9600);           // Inicializa a comunicação serial a 9600 bps

  // Configuração dos pinos como saída ou entrada
  pinMode(led, OUTPUT);         // Define o pino do LED como saída
  pinMode(buzina, OUTPUT);      // Define o pino da buzina como saída
  pinMode(motor, OUTPUT);       // Define o pino do motor como saída
  pinMode(A0, INPUT);           // Define o pino A0 (analógico) como entrada para leitura do sensor de temperatura
}

void loop()
{
  // Lê o valor analógico do sensor de temperatura
  sensor = analogRead(A0);

  // Converte o valor do sensor em temperatura usando uma fórmula aproximada
  temperatura = map(((sensor - 20) * 3.04), 0, 1023, -40, 125);

  // Exibe no monitor serial o valor bruto do sensor
  Serial.print("Medida do sensor = ");
  Serial.println(sensor);
  delay(1000);  // Espera 1 segundo

  // Exibe no monitor serial o valor convertido de temperatura
  Serial.print("Temperatura = ");
  Serial.println(temperatura);
  delay(1000);  // Espera 1 segundo

  // Verifica se a temperatura está acima de 30°C
  if(temperatura >= 30){
    digitalWrite(motor, HIGH);  // Liga o motor

    // Se a temperatura estiver acima de 50°C, aciona LED e buzina
    if(temperatura >= 50){
      digitalWrite(led, HIGH);     // Liga o LED
      digitalWrite(buzina, HIGH);  // Liga a buzina
    } else {
      digitalWrite(led, LOW);      // Desliga o LED
      digitalWrite(buzina, LOW);   // Desliga a buzina
    }
  } else {
    digitalWrite(motor, LOW);   // Desliga o motor se a temperatura for menor que 30°C
  }
}