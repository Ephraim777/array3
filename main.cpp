#include <iostream>


void print_dynamic_array(int* arr, int logical_size, int actual_size)
{

    std::cout << "Array: ";
    if(actual_size == 0){
        std::cout << "_";
        return;
    }
    for (int i = 0; i < actual_size; i++)
    {
       if(i < logical_size)
       {
           std::cout << arr[i];
       }
       else
       {
           std::cout << "_";
       }
       std::cout << " ";
    }
}

void append_to_dynamic_array(int ** arr, int &logical_size, int &actual_size)
{
  while(true)
  {
  std::cout << std::endl;
  std::cout << "Enter a num: \n";
  int num;
  std::cin >> num;
  if(num == 0)
  {
  std::cout << "goodbay)\n";
  print_dynamic_array(*arr,logical_size,actual_size);
  break;
  }
  if(logical_size < actual_size)
{
    (*arr)[logical_size] = num;
    logical_size++;
}
  else if(logical_size == actual_size)
{
  actual_size *= 2;
  int * arr1 = new int[ actual_size];
  for(int i = 0; i < logical_size; i++)
{
  arr1[i] = (*arr)[i];
}
  arr1[logical_size] = num;
  logical_size++;
  delete [] *arr;
  *arr = arr1;
}
      print_dynamic_array(*arr,logical_size,actual_size);
  }
}

void remove_dynamic_array_head(int ** arr, int &logical_size, int &actual_size)
{
while(true){
std::cout << std::endl;
std::cout << "Remove element?\n";
std::string answer;
std::cin >> answer;
if(answer == "нет")
{
std::cout << "Thank\n";
return;
}
else if (answer == "да")
{
if(logical_size == 0)
{
std::cout << "Array is empty\n";
return;
}
if (logical_size - 1 > actual_size/3)
{
for (int i = 0; i < logical_size; i++)
{
    (*arr)[i] = (*arr)[i+1];
}
}else if (--logical_size <= actual_size/3)
{
actual_size /= 3;
int * arr1 = new int [actual_size];
int j = 1;
for(int i = 0; i < logical_size; i++)
{
    arr1[i] = (*arr)[j++];
}
delete [] *arr;
*arr = arr1;}

}

print_dynamic_array(*arr,logical_size,actual_size);

}}

int main()
{
int logical_size;
int actual_size;
while(true)
{
std::cout << "Enter actual size array: ";
std::cin >> actual_size;
std::cout << std:: endl;
std::cout << "Enter logical size array: ";
std::cin >> logical_size;
std::cout << std::endl;
if (logical_size <= actual_size)
{
    break;
}
else
{
std::cout << "logical size > actual size it is not correct\n";
}
}

int * arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Enter arr["<< i <<"]: ";
        std::cin >> arr[i];
        std::cout << std::endl;
    }

print_dynamic_array(arr,logical_size,actual_size);


append_to_dynamic_array(&arr,logical_size,actual_size);

remove_dynamic_array_head(&arr,logical_size,actual_size);

print_dynamic_array(arr,logical_size,actual_size);

delete [] arr;

    return 0;
}