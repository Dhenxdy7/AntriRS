#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 10

using namespace std;

int nomer[MAX];
int head=-1;
int tail=-1;

//Fungsi Untuk pengecekan antrian Loket
bool IsEmpty()
{
  if(tail == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool IsFull()
{
  if(tail == MAX-1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Fungsi untuk memasukan antrian loket (queue) kedalam array
void AntrianMasuk(int no)
{
  if(IsEmpty())
  {
    head=tail=0;
  }
  else
  {
    tail++;
  }
  nomer[tail]=no;
}

//Fungsi untuk menghapus antrian loket
void AntrianKeluar()
{
  if(IsEmpty())
  {
    cout<<"Antrian Loket sudah kosong ! ";
    getch();
  }
  else
  {
    for(int a=head;a<tail;a++)
    {
      nomer[a]=nomer[a+1];
    }
    tail--;
    if(tail ==- 1)
    {
      head = -1;
    }
  }
}

//Fungsi untuk menghapus semua antrian
void Clear()
{
  head=tail=-1;
}

//Fungsi untuk melihat semua antrian
void View()
{
  if(IsEmpty())
  {
    cout<<"Antrian Loket kosong ! ";
  }
  else
  {
    system("cls");
    for(int a=head;a<=tail;a++)
    {
      cout << "========================================="
           << "\n >> No. Antri Loket : [" << nomer[a] << "]"
           << "\n========================================" << endl;
    }
  }
}

int main()
{
  //system("color 80");
  int choose, p=1, urut;
  do
  {
    system("cls");
    cout << "\n\n====== Stasiun Lempuyangan ======"
         << "\n================================="
         << "\n|1. Tambah Antrian Loket Kereta              "
         << "\n|2. Layani Antrian Loket Kereta              "
         << "\n|3. Lihat daftar Antrian Loket               "
         << "\n|4. Hapus Antrian Loket                      "
         << "\n|5. Tutup Antrian Loket Stasiun              "
         << "\n|================================";
    cout << "\nChoose ! "; cin >> choose;
    cout << "\n\n";
    if(choose == 1)
    {
      if(IsFull())
      {
        cout << "Loket Kereta penuh, mohon tunggu beberapa saat lagi";
      }
      else
      {
        urut=p;
        AntrianMasuk(urut);
        cout << "---------------------------------------------" << endl;
        cout << "|            NO. ANTRIAN LOKET              |" << endl;
        cout << "|                    " << p << "                      |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|            Silahkan Mengantri             |" << endl;
        cout << "|            Menunggu " << tail << " Antrian             |" << endl;
        cout << "---------------------------------------------" << endl;
        p++;
      }
    } 
    else if(choose ==2)
    {
      cout << "---------------------------------" << endl;
      cout << "       Stasiun Lempuyangan       " << endl;
      cout << "---------------------------------" << endl;
      cout << "No. Antri Loket : ["<< nomer[head] <<    "]";
      cout << "\n=================================" << endl;
      AntrianKeluar();
      cout << "Silahkan Dipanggil !" << endl;
    }
    else if(choose ==3)
    {
      View();
    } 
    else if(choose ==4)
    {
      Clear();
      cout << "Antrian Loket dikosongkan ! ";
    }
    else if(choose ==5)
    {
      cout << "Loket Stasiun Lempuyangan Berhenti Beroperasi"; 
    }
    else
    {
      cout << "Masukan anda salah! \n" << endl;
    }
    getch();
  }
  while(choose!=5);
}