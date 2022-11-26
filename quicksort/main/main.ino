const unsigned int size = 10;
int* numbers = new int[(int)size]{ 10, 4, 2, 8, 9, 1, 3, 5, 7, 6 };
// 10, 4, 2, 8, 9, 1, 3, 5, 7, 6
// 5, 4, 2, 3, 1, 9, 8, 10, 7, 6
// 5, 4, 2, 3, 1, 6, 8, 10, 7, 9
// 1, 4, 2, 3, 5

//int* numbers = new int[(int)size]{ 1, 2, 3};

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  unsigned long time = millis();
  Sort(0, size - 1);

  for(int i = 0; i < size; i++){
    Serial.print(String(numbers[i]));
    Serial.print(",");
  }
}
                
void loop() {
  // put your main code here, to run repeatedly:
}

void Sort(int leftIndex, int rightIndex) {
  if (leftIndex < rightIndex) {
    int index = Split(leftIndex, rightIndex);
    Sort(leftIndex, index - 1);
    Sort(index + 1, rightIndex);
  }
}

int Split(int leftIndex, int rightIndex) {
  int i = leftIndex;
  int j = rightIndex - 1;
  int p = numbers[rightIndex];

  //Serial.println("in " + String(i) + ", " + String(j) + ", " + String(p));
  //delay(1000);
  
  while (i < j) {
    while (i < j && numbers[i] <= p) {
      i++;
    }

    while (j > i && numbers[j] > p) {
      j--;
    }

    if (numbers[i] > numbers[j]) {
      //Serial.println("swap " + String(numbers[i]) + " with " + String(numbers[j]));
      int t = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = t;
    }
  }

  if (numbers[i] > p) {
    //Serial.println("swap " + String(numbers[i]) + " with pivot " + String(numbers[rightIndex]));
    int t = numbers[i];
    numbers[i] = numbers[rightIndex];
    numbers[rightIndex] = t;
  } else {
    i = rightIndex;
  }

  return i;
}

class T{

};