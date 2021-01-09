int led = 3;
int brillo = 0;
int max_brillo = 50;
int min_brillo = 0;
boolean subir_intensidad = true;

void setup() {
  // ponemos el pin como salida
  pinMode(led, OUTPUT);

  // para imprimir por consola
  Serial.begin(9600);
}

void loop() {
  if (subir_intensidad && brillo < max_brillo){
    // si estamos en fase de subir la luz y todavia no ha llegado al maximo
    brillo++;
  }else if (subir_intensidad && brillo == max_brillo){
    // ahora toca bajar la luz
    subir_intensidad = false;
  }

  if (!subir_intensidad && brillo > min_brillo){
    // estamos en fase de bajar la luz y todavia no hemos llegado al minimo
    brillo--;
  }else if (!subir_intensidad && brillo == min_brillo){
    // ahora toca subir la luz
    subir_intensidad = true;
  }

  // mostramos el valor actual del brillo
  Serial.println(brillo);

  analogWrite(led, brillo);
  
  //esperamos un tiempo entre iteracion
  delay(10);
}
