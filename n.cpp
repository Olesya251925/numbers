/*******************************************
 *        Автор: Кириллова Олеся.          *
 *           Группа: ПИ-221                *
 *******************************************/
#include <iostream>
#include <string>
using namespace std;
void fromArabicToRoman(int arabic) {
  const string unitsRoman[10] = {
    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
  },
  tensRoman[10] = {
    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
  },
  hundredsRoman[10] = {
    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
  };

  int units = arabic % 10;
  int tens = arabic % 100 / 10;
  int hundreds = arabic % 1000 / 100;
  int thousands = arabic / 1000;
    
  string thousandsRoman = "";
	
  for (int thousandsCount = thousands; thousandsCount > 0; --thousandsCount) {
    thousandsRoman += "M";
  } 
  cout << "Арабская " << arabic << " Римская " << thousandsRoman << hundredsRoman[hundreds] << tensRoman[tens] << unitsRoman[units] << endl << '\n';        
}

void fromRomanToArabic(string roman) {
  int number = int(roman.length());
  int result = 0;
  for (int index = 0; index < number; ++index) {
    switch (roman[index]) {
      case 'I':
        result += 1;
        break;
      case 'V':
        result += 5;
        break;
      case 'X':
        result += 10;
        break;
      case 'L':
        result += 50;
        break;
      case 'C':
        result += 100;
        break;
      case 'D':
        result += 500;
        break;
      case 'M':
        result += 1000;
        break;
    }
  }
  for (int index = 1; index < number; ++index) {
  
    if ((roman[index] == 'V' || roman[index] == 'X' || roman[index] == 'L' || roman[index] == 'C' || roman[index] == 'D' || roman[index] == 'M') && roman[index - 1] == 'I') {
      result -= 1 + 1;
	  }

    if ((roman[index] == 'X' || roman[index] == 'L' || roman[index] == 'C'  || roman[index] == 'D' || roman[index] == 'M') && roman[index - 1] == 'V') {
      result -= 5 + 5;
	  
    }
	
	  if ((roman[index] == 'L' || roman[index] == 'C' || roman[index] == 'D' || roman[index] == 'M') && roman[index - 1] == 'X') {
	  result -= 10 + 10;
    }

    if ((roman[index] == 'C' || roman[index] == 'D' || roman[index] == 'M') && roman[index - 1] == 'L') {
      result -= 50 + 50;
    }
    
    if ((roman[index] == 'D' || roman[index] == 'M') && roman[index - 1] == 'C') {
	  result -= 100 + 100;
    }
    
    if ((roman[index] == 'M') && roman[index - 1] == 'D') {
      result -= 500 + 500;
    }
    
    cout << "Римская " << roman << " Арабская " << result << endl;
    }
}

int main() {
  int arabic;
  int selection;
  string roman;
  
  cout << "1 - Преобразование арабских цифр в римские цифры"    << endl;
  cout << "2 - Преобразование римских цифр в арабские цифры\n " << endl;
  cin  >> selection ;
  cout << "\n" ;
  
  if (selection == 1 || selection == 2) {
    if (selection == 1) {
	  cout << "Введите арабское число, которое вы хотите преобразовать: ";
	  cin  >> arabic;
	  fromArabicToRoman(arabic);
	}
	if (selection == 2) {
	  cout << "Введите римское число, которое вы хотите преобразовать: ";
      cin  >> roman;
      fromRomanToArabic(roman);
      
	}
  } else {
	  cout << "Неправильный ввод";
	  return 0;
	}
}
   
