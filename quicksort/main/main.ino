const unsigned int size = 10;
int* numbers = new int[(int)size]{ 10, 4, 2, 8, 9, 1, 3, 5, 7, 6 };


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  unsigned long time = millis();
  Sort(0, size);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void Sort(unsigned int leftIndex, unsigned int rightIndex) {
  if (leftIndex < rightIndex) {
    unsigned int index = Split(leftIndex, rightIndex);
    Sort(leftIndex, index - 1);
    Sort(index + 1, rightIndex);
  }
}

unsigned int Split(unsigned int leftIndex, unsigned int rightIndex) {
  unsigned int i = leftIndex;
  unsigned int j = rightIndex - 1;
  int p = numbers[rightIndex];

  Serial.println("test");
  delay(1000);
  
  while (i < j) {
    while (i < j && numbers[i] <= p) {
      i++;
    }

    while (j > i && numbers[j] > p) {
      j--;
    }

    if (numbers[i] > numbers[j]) {
      Serial.println("swap " + String(numbers[i]) + " with " + String(numbers[j]));
      int t = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = t;
    }
  }

  if (numbers[i] > p) {
    //Serial.println("swap " + numbers[i] + " with pivot " + numbers[rightIndex]);
    int t = numbers[i];
    numbers[i] = numbers[rightIndex];
    numbers[rightIndex] = t;
  } else {
    i = rightIndex;
  }

  return i;
}