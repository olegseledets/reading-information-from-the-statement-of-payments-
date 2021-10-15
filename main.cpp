#include <iostream>
#include <fstream>

int main() {
  std::ifstream payroll;
  std::string firstName, lastName, date, fullName;
  int pay = 0, totalSum = 0, maxPay = 0;

  payroll.open("payroll.txt");
  if (payroll.is_open()) {
    while (!payroll.eof()) {
      payroll >> firstName >> lastName >> pay >> date;
      totalSum += pay;
      if (pay > maxPay) {
        maxPay = pay;
        fullName = firstName + " " + lastName;
      }
    }
  } else {
    std::cout << "File not found!";
  }

  payroll.close();

  std::cout << "total sum: " << totalSum << std::endl;
  std::cout << "maximum payout: " << fullName << " - " << maxPay;
}

/*
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу: 

имя и фамилия человека; 
количество денег, которые были выплачены лицу; 
дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной суммой выплат.
*/