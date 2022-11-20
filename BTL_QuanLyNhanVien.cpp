	#include<iostream>
	#include <windows.h>
	#define WIDTH 30
	#define HEIGHT 15
	#define X 10
	#define Y 4
	using namespace std;
	struct NhanVien {
		string HoTen;
		int SoNha;
		string Duong,Phuong,ThanhPho;
		int Ngay,Thang,Nam;
		string GioiTinh,ChucVu;
		int	Luong;
	};
	int Nhap();
	void Xuat(NhanVien nv);
	void GoToXY(int x, int y);
	void SetColor(int a);
	void Open();
	void Menu();
	int Nhap(NhanVien& nv) {
		cout<<char(175)<<" Nhap Nhan Vien"<<endl;
	   bool Name  = true;
	    do {
	        cout << "Nhap Ho Ten Nhan Vien : ";
	        fflush(stdin);
	        getline(cin, nv.HoTen);
	        for (int i = 0; i < nv.HoTen.length(); i++) {
	            if (nv.HoTen[i] >= 'a' && nv.HoTen[i] <= 'z' || nv.HoTen[i] >= 'A' && nv.HoTen[i] <= 'Z' || nv.HoTen[i] == ' ') {
	                Name = true;
	            } else {
	                Name = false;
	                break;
	            }
	        }
	    } while (! Name);
		fflush(stdin);
		bool NgaySinh = true;
			cout<<"Nhap Ngay Sinh nhan vien : " << endl;
		    do {
		        do {
		            cout << "\tNhap Thang sinh: ";
		            cin >> nv.Thang;
		        } while (nv.Thang < 1 || nv.Thang > 12);
		        do {
		            cout << "\tNhap Ngay sinh: ";
		            cin >> nv.Ngay;
		        } while (nv.Ngay < 1 || nv.Ngay > 31);
		        do {
		            cout << "\tNhap Nam sinh: ";
		            cin >> nv.Nam;
		        } while (nv.Nam > 2004);
		        if (nv.Thang == 2) {
		            if (nv.Nam % 4 == 0 && nv.Nam % 100 != 0 || nv.Nam % 400 == 0) {
		                if (nv.Ngay > 29) {
		                    NgaySinh = false;
		                } else {
		                    NgaySinh = true;
		                }
		            } else {
		                if (nv.Ngay > 28) {
		                    NgaySinh = false;
		                } else {
		                    NgaySinh = true;
		                }
		            }
		        } else if (nv.Thang == 4 || nv.Thang == 6 || nv.Thang == 9 || nv.Thang == 11) {
		            if (nv.Ngay > 30) {
		                NgaySinh = false;
		            } else {
		                NgaySinh = true;
		            }
		        } else {
		            NgaySinh = true;
		        }
		    } while (! NgaySinh);
	 	bool GioiTinh  = true;
	    	do {
		        cout << "Nhap Gioi Tinh Nhan Vien : ";
		        fflush(stdin);
		        getline(cin, nv.GioiTinh);
	        	for (int i = 0; i < nv.GioiTinh.length(); i++) {
		            if (nv.GioiTinh[i] >= 'a' && nv.GioiTinh[i] <= 'z' || nv.GioiTinh[i] >= 'A' && nv.GioiTinh[i] <= 'Z' || nv.GioiTinh[i] == ' ') {
		                GioiTinh = true;
		            } else {
		                GioiTinh = false;
		                break;
		            }
		        }
	    	} while (! GioiTinh);
		bool ChucVu  = true;
		    do {
		        cout << "Nhap Chuc Vu Nhan Vien : ";
		        fflush(stdin);
		        getline(cin, nv.ChucVu);
		        for (int i = 0; i < nv.ChucVu.length(); i++) {
		            if (nv.ChucVu[i] >= 'a' && nv.ChucVu[i] <= 'z' || nv.ChucVu[i] >= 'A' && nv.ChucVu[i] <= 'Z' || nv.ChucVu[i] == ' ') {
		                ChucVu = true;
		            } else {
		                ChucVu = false;
		                break;
		            }
		        }
		    } while (! ChucVu);
		bool DiaChi = true;
			cout << "Nhap Dia Chi :"<<endl;
		   do {
	        do {
	            cout << "\tSo Nha: ";
	            cin >> nv.SoNha;
	        } while (nv.SoNha < 0);
	        do {
	              cout << "\tNhap Ten Duong : ";
		        fflush(stdin);
		        getline(cin, nv.Duong);
		        for (int i = 0; i < nv.Duong.length(); i++) {
		            if (nv.Duong[i] >= 'a' && nv.Duong[i] <= 'z' || nv.Duong[i] >= 'A' && nv.Duong[i] <= 'Z' || nv.Duong[i] == ' ') {
		                DiaChi = true;
		            } else {
		                DiaChi = false;
		                break;
		            }
		        }
		    } while (! DiaChi);
		    do {
	              cout << "\tNhap Ten Phuong : ";
		        fflush(stdin);
		        getline(cin, nv.Phuong);
		        for (int i = 0; i < nv.Phuong.length(); i++) {
		            if (nv.Phuong[i] >= 'a' && nv.Phuong[i] <= 'z' || nv.Phuong[i] >= 'A' && nv.Phuong[i] <= 'Z' || nv.Phuong[i] == ' ') {
		                DiaChi = true;
		            } else {
		                DiaChi = false;
		                break;
		            }
		        }
		    } while (! DiaChi);
		    do {
	              cout << "\tNhap Ten Thanh Pho : ";
		        fflush(stdin);
		        getline(cin, nv.ThanhPho);
		        for (int i = 0; i < nv.ThanhPho.length(); i++) {
		            if (nv.ThanhPho[i] >= 'a' && nv.ThanhPho[i] <= 'z' || nv.ThanhPho[i] >= 'A' && nv.ThanhPho[i] <= 'Z' || nv.ThanhPho[i] == ' ') {
		                DiaChi = true;
		            } else {
		                DiaChi = false;
		                break;
		            }
		        }
		    } while (! DiaChi);
	    	 DiaChi = true;
	    } while (! DiaChi);
		cout << "Nhap Luong cua nhan vien: ";
		cin >> nv.Luong;}
	void Xuat(NhanVien nv){
		cout << "Ten : " << nv.HoTen << endl;
		cout << "Nhap Ngay Sinh : "<<nv.Ngay<<"/"<<nv.Thang<<"/"<<nv.Nam<< endl;
		cout << "Gioi Tinh : " << nv.GioiTinh << endl;
		cout << "Chuc Vu : " << nv.ChucVu << endl;
		cout << "Dia Chi :" << " so"<<nv.SoNha<< " Duong." <<nv.Duong<<" P. "<<nv.Phuong<<" Tp."<<nv.ThanhPho<<endl;
		cout << "Luong :" << nv.Luong <<" VND "<< endl;}
	void GoToXY(int x,int y)
	{
	    HANDLE hConsoleOutput;
	    COORD Cursor_an_Pos = { x,y};
	    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
	}
	void SetColor(int a)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, a);
	}
	struct Node {
		NhanVien data;
		Node* next;
	};
	struct List {
		Node* head;
		Node* tail;
		List();
		Node* createNode(NhanVien x);
		void addFirst(NhanVien x);
		void addLast(NhanVien x);
		void insert(NhanVien x, int pos);
		void removeFirst();
		void removeLast();
		void remove(int pos);
		void removeName(NhanVien x);
		void print();
		int count(NhanVien x);
		void sort();
		void seach(NhanVien x);
		void Statistical(NhanVien x);
	};
	List::List() {
		head = tail = NULL;
	}
	Node* List::createNode(NhanVien x) {
		Node* p = new Node;
		p->data = x;
		p->next = NULL;
		return p;
	}
	void List::addFirst(NhanVien x) {
		Node* p = createNode(x);
		if (head == NULL)
			head = tail = p;
		else {
			p->next = head;
			head = p;
		}
	}
	void List::print() {
		for (Node *i=head; i != NULL; i = i->next) {
			Xuat(i->data);
		}
	}
	void List::addLast(NhanVien x) {
		Node* p = createNode(x);
		if (head == NULL)
			head = tail = p;
		else {
			tail->next = p;
			tail = p;
		}
	}
	void List::insert(NhanVien x,int pos){
		cout<<"Nhap vi tri can chen :";
		cin>>pos;
		Node *p=new Node;
		if(pos==0||p==NULL){
			addFirst(x);
			 int k = 1;
	        while(p != NULL && k != pos){
	        	p=head;
	            p = p->next;
	            ++k;}
	    if(k != pos){
	            	addLast(x);
	            	}else{
	            Node *temp = createNode(x);
	            temp->next = p->next;
	            p->next = temp;
	        }
	    }
		}
	void List::removeFirst() {
		Node* p = new Node;
		if (head == NULL) 
			cout << "Khong co Nhan vien de xa thai "<<endl;
		else {
			head = head->next;
			p = head;
		}
	}
	void List::removeLast() {
		if (head == NULL)
			cout << "Khong co Nhan vien de xa thai "<<endl;
	 for(Node*k=head;k!=NULL;k=k->next)
		if(k->next==tail){
			delete tail;
			k->next = NULL;
			tail = k;
		}
	}
	void List::remove(int pos){
		cout<<"Nhap vi tri nhan vien trong danh sach can xa thai :"<<endl;
		cin>>pos;
		Node *p=new Node;
		if(pos == 0 || head == NULL || head->next == NULL){
	        removeFirst();
	    }else{
	        int k = 1;
			p = head;
	        while(p->next->next != NULL && k != pos){
	            p = p->next;
	            ++k;
	        }
	 
	        if(k != pos){
	            removeLast();
	        }else{
	            p->next = p->next->next;
	        }
	    }
	}
	int List::count(NhanVien x)
	{ 	
	    Node *p=createNode(x);
	    int Size=0;
	    p=head;
	    while(p!=NULL)
	    {
	        p=p->next;
	        Size++;
	    }
	        cout<< "So Nhan Vien co trong danh sach la : "<<Size<<"  Nhan Vien"<<endl<<endl;
	}
	void List::sort(){
		Node *p,*q,*min;
	    p=head;
	    NhanVien temp;
	    while (p!=tail)
	    {
	        min=p;
	        q=p->next;
	        while (q!=NULL)
	        {
	            if(q->data.Luong<min->data.Luong)  min=q;
	            q=q->next;
	        }
	        temp=p->data;
	        p->data=min->data;
	        min->data=temp;
	        p=p->next;
	    }}
	void List::seach(NhanVien nv){
		Node *p;
	    int dem=0;
	    string k;
	   bool Name  = true;
	    do {
	        cout << "Nhap Ho Ten Nhan Vien : ";
	        fflush(stdin);
	        getline(cin, nv.HoTen);
	        for (int i = 0; i < nv.HoTen.length(); i++) {
	            if (nv.HoTen[i] >= 'a' && nv.HoTen[i] <= 'z' || nv.HoTen[i] >= 'A' && nv.HoTen[i] <= 'Z' || nv.HoTen[i] == ' ') {
	                Name = true;
	            } else {
	                Name = false;
	                break;
	            }
	        }
	    } while (! Name);
	    p=head;
	    while (p!=NULL)
	    {
	        if(nv.HoTen==p->data.HoTen)      dem++;
	        p=p->next;
	    }
	    if(dem!=0)
	    {
	            cout<<"Tim thay Nhan Vien :"<<endl;
	            Xuat(nv);
	    }
	    else cout<<"Ko tim thay Nhan Vien "<<endl;
	}
	void List::Statistical(NhanVien x)
	{
	    Node *p;
	    int dem=0;
	    p=head;
	    while (p!=NULL)
	    {       
	        if(p->data.Luong>=10000000)  dem++;
	        p=p->next;
	    }
	    if(dem==0)  cout<<"\nKo co Nhan Vien co Luong >= 10.000.000 VND "<<endl;
	    else {
	    	cout<<"So Nhan Vien co Luong >=10.000.000 VND "<<dem<<endl;
	    	Xuat(x);
		}
	}
	void Menu(){
	system("cls");
		NhanVien x;
		int t,pos;
		List l;
		short i;
		SetColor(9);
		GoToXY(10, 1);
		cout<<char(218);
		for (i = 0; i<2 * WIDTH; i++)
			cout<<char(196);
		cout<<char(191);
		GoToXY(10, 2);
		cout<<char(179);
		SetColor(4);
		GoToXY(30,2);
		cout<<char(175)<<char(175)<<" QUAN LY NHAN VIEN "<<char(174)<<char(174);
		SetColor(9);
		GoToXY(71,2);
		cout<<char(179);
		GoToXY(10, 3);
		cout<<char(192);
		for (i = 0; i <2 * WIDTH; i++)
			cout<<char(196);
		cout<<char(217);
		GoToXY(35,6);
		SetColor(10);
		cout<<" M E N U ";
		GoToXY(X,Y);
		SetColor(9);
		cout<<char(201);
		for (i = 0; i < 2 * WIDTH; i++)
			cout<<char( 205);
		cout<<char( 187);
		for (i = 0; i < HEIGHT; i++)
		{
			GoToXY(X, Y + 1 + i);
			cout<<char( 186);
			GoToXY(X + 1 + 2 * WIDTH, Y + 1 + i);
			cout<<char( 186);
		}
		GoToXY(X, Y + 1 + HEIGHT);
		cout<<char(200);
		for (i = 0; i < 2 * WIDTH; i++)
			cout<<char(205);
		cout<<char(188);
		SetColor(6);
		GoToXY(15,8);	cout<<	"	1.Them nhan vien vao dau danh sach";
		GoToXY(15,9);	cout<<	"	2.Them nhan vien vao cuoi danh sach.";
		GoToXY(15,10);	cout<<	"	3.Them nhan vien vao vi tri bat ky trong danh sach.";
		GoToXY(15,11);	cout<<	"	4.Xa thai nhan vien.";
		GoToXY(15,12);	cout<<	"	5.Dem so nhan vien.";
		GoToXY(15,13);	cout<<	"	6.Kiem tra nhan vien co nam trong danh sach hay khong ";
		GoToXY(15,14);	cout<<	"	7.Sap xep luong nhan vien tang dan.";
		GoToXY(15,15);	cout<<	"	8.Thong ke nhan vien co luong >= 10.000.000 VND .";
		GoToXY(15,16);	cout<<	"	9.In danh sach nhan vien .";
		GoToXY(15,17);	cout<<	"	0.Exit";
		GoToXY(0,22);
		do{	SetColor(12);
		cout<<char(205)<<char(205)<<char(205)<<char(175)<<" Chon thao tac thuc hien : ";
		cin>> t;
		SetColor(15);
		switch(t){
			case 1:
				Nhap(x);
				l.addFirst(x);
				break;
			case 2:
				Nhap(x);
				l.addLast(x);
				break;
			case 3:
				Nhap(x);
				l.insert(x,pos);
				break;
			case 4:
				l.remove(pos);
				break;
			case 5:
				l.count(x);
				break;
			case 6:
				l.seach(x);
				break;
			case 7:	
				l.sort();
				break;
			case 8:
				l.Statistical(x);
				break;				
			case 9:
				l.print();
				break;
			case 0:
	                cout << "Thoat chuong trinh" << endl;
	                break;
	        default:
	                cout << "Nhap sai, vui long nhap lai" << endl;
	                break;
		}
		}while(t!=0);
	}
	int main(){
		Menu();
	}
