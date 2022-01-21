#include <bits/stdc++.h>

using namespace std;

struct Student {
  string name;
  int math;
  int phys;
  int chem;
  int total;
  int rank;
};

// function for comparing two students according to given rules

bool compareTwoStudents(Student a, Student b) {
  // If total marks are not the same then returns true for higher total
  if (a.total != b.total)
    return a.total > b.total;

  if (a.math != b.math)
    return a.math > b.math;

  if (a.phys != b.phys)
    return a.phys > b.phys;

  return (a.chem > b.chem);
}

// Fills total marks and ranks of all Students
void computeRanks(Student a[], int n) {

  // To calculate total marks for all Students
  for (int i = 0; i < n; i++)
    a[i].total = a[i].math + a[i].phys + a[i].chem;

  // Sort Structure array using user defined
  // Function compareTwoStudents()
  sort(a, a + 5, compareTwoStudents);

  // Assigning ranks after sorting
  for (int i = 0; i < n; i++)
    a[i].rank = i + 1;
}

// Driver code
int main() {
  int n = 5;

  // array of structure objects
  Student a[n];

  // Details of Student 1
  a[0].name = "Bryan";
  a[0].math = 80;
  a[0].phys = 95;
  a[0].chem = 85;

  // Details of Student 2
  a[1].name = "Kevin";
  a[1].math = 95;
  a[1].phys = 85;
  a[1].chem = 99;

  // Details of Student 3
  a[2].name = "Nicky";
  a[2].math = 95;
  a[2].phys = 85;
  a[2].chem = 80;

  // Details of Student 4
  a[3].name = "Steve";
  a[3].math = 80;
  a[3].phys = 70;
  a[3].chem = 90;

  // Details of Student 5
  a[4].name = "Rohan";
  a[4].math = 80;
  a[4].phys = 80;
  a[4].chem = 80;

  computeRanks(a, n);

  // Column names for displaying data
  cout << "Rank"
       << " "
       << "Name"
       << "     ";
  cout << "Maths"
       << " "
       << "Physics"
       << " "
       << "Chemistry";
  cout << " "
       << "Total\n";

  // Display details of Students
  for (int i = 0; i < n; i++) {
    cout << a[i].rank << "    ";
    cout << a[i].name << "      ";
    cout << a[i].math << "     " << a[i].phys << "     " << a[i].chem
         << "       ";
    cout << a[i].total << " ";
    cout << "\n";
  }

  return 0;
}