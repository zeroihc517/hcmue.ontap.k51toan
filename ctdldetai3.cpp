#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdio>

using namespace std;

// ==================== CAU HINH GIAO DIEN ====================

const int COLOR_VIEN = 11;
const int COLOR_TIEU_DE = 14;
const int COLOR_TEXT = 15;
const int COLOR_CHON = 10;
const int COLOR_LOI = 12;
const int WIDTH_FRAME = 106;

void setColor(int mau)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mau);
}

void printEffect(string text, int mau, int delay = 5)
{
    setColor(mau);

    for (int i = 0; i < (int)text.length(); i++)
    {
        cout << text[i];
        Sleep(delay);
    }
}

string toStr(int x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

string getNgayHienTai()
{
    time_t now = time(0);
    tm* t = localtime(&now);

    char ngay[20];
    sprintf(ngay, "%02d/%02d/%04d",
            t->tm_mday,
            t->tm_mon + 1,
            t->tm_year + 1900);

    return string(ngay);
}

string getNgayTra()
{
    time_t now = time(0) + 7 * 24 * 60 * 60;
    tm* t = localtime(&now);

    char ngay[20];
    sprintf(ngay, "%02d/%02d/%04d",
            t->tm_mday,
            t->tm_mon + 1,
            t->tm_year + 1900);

    return string(ngay);
}

vector<string> split(string s, char kyTu)
{
    vector<string> a;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, kyTu))
    {
        a.push_back(temp);
    }

    return a;
}

// ==================== CLASS SACH ====================

class Sach
{
private:
    string maSach;
    string tenSach;
    string tacGia;
    string nxb;
    double giaBan;
    int namPhatHanh;
    int soTrang;
    string ngayNhapKho;
    int tinhTrang;

public:
    Sach()
    {
        giaBan = 0;
        namPhatHanh = 0;
        soTrang = 0;
        tinhTrang = 0;
    }

    Sach(string ma, string ten, string tg, string nhaXb,
         double gia, int nam, int trang, string ngay, int tt)
    {
        maSach = ma;
        tenSach = ten;
        tacGia = tg;
        nxb = nhaXb;
        giaBan = gia;
        namPhatHanh = nam;
        soTrang = trang;
        ngayNhapKho = ngay;
        tinhTrang = tt;
    }

    string getMaSach() const
    {
        return maSach;
    }

    string getTenSach() const
    {
        return tenSach;
    }

    string getTacGia() const
    {
        return tacGia;
    }

    string getNxb() const
    {
        return nxb;
    }

    double getGiaBan() const
    {
        return giaBan;
    }

    int getNamPhatHanh() const
    {
        return namPhatHanh;
    }

    int getSoTrang() const
    {
        return soTrang;
    }

    string getNgayNhapKho() const
    {
        return ngayNhapKho;
    }

    int getTinhTrang() const
    {
        return tinhTrang;
    }

    void setMaSach(string ma)
    {
        maSach = ma;
    }

    void setTenSach(string ten)
    {
        tenSach = ten;
    }

    void setTacGia(string tg)
    {
        tacGia = tg;
    }

    void setNxb(string nhaXb)
    {
        nxb = nhaXb;
    }

    void setGiaBan(double gia)
    {
        giaBan = gia;
    }

    void setNamPhatHanh(int nam)
    {
        namPhatHanh = nam;
    }

    void setSoTrang(int trang)
    {
        soTrang = trang;
    }

    void setNgayNhapKho(string ngay)
    {
        ngayNhapKho = ngay;
    }

    void setTinhTrang(int tt)
    {
        tinhTrang = tt;
    }
};

// ==================== CLASS BAN DOC ====================

class BanDoc
{
private:
    string maBD;
    string hoTen;
    string ngayDK;

public:
    BanDoc() {}

    BanDoc(string ma, string ten, string ngay)
    {
        maBD = ma;
        hoTen = ten;
        ngayDK = ngay;
    }

    string getMaBD() const
    {
        return maBD;
    }

    string getHoTen() const
    {
        return hoTen;
    }

    string getNgayDK() const
    {
        return ngayDK;
    }

    void setMaBD(string ma)
    {
        maBD = ma;
    }

    void setHoTen(string ten)
    {
        hoTen = ten;
    }

    void setNgayDK(string ngay)
    {
        ngayDK = ngay;
    }
};

// ==================== CLASS PHIEU MUON ====================

class PhieuMuon
{
private:
    int soPhieu;
    string maBD;
    string maSach;
    string ngayMuon;
    string ngayTra;
    int tinhTrang;

public:
    PhieuMuon()
    {
        soPhieu = 0;
        tinhTrang = 0;
    }

    PhieuMuon(int so, string maNguoiMuon, string ma,
              string ngayM, string ngayT, int tt)
    {
        soPhieu = so;
        maBD = maNguoiMuon;
        maSach = ma;
        ngayMuon = ngayM;
        ngayTra = ngayT;
        tinhTrang = tt;
    }

    int getSoPhieu() const
    {
        return soPhieu;
    }

    string getMaBD() const
    {
        return maBD;
    }

    string getMaSach() const
    {
        return maSach;
    }

    string getNgayMuon() const
    {
        return ngayMuon;
    }

    string getNgayTra() const
    {
        return ngayTra;
    }

    int getTinhTrang() const
    {
        return tinhTrang;
    }

    void setSoPhieu(int so)
    {
        soPhieu = so;
    }

    void setMaBD(string ma)
    {
        maBD = ma;
    }

    void setMaSach(string ma)
    {
        maSach = ma;
    }

    void setNgayMuon(string ngay)
    {
        ngayMuon = ngay;
    }

    void setNgayTra(string ngay)
    {
        ngayTra = ngay;
    }

    void setTinhTrang(int tt)
    {
        tinhTrang = tt;
    }
};

// ==================== CLASS QUAN LY THU VIEN ====================

class QuanLyThuVien
{
private:
    vector<Sach> dsSach;
    vector<BanDoc> dsBanDoc;
    vector<PhieuMuon> dsPhieuMuon;

public:
    QuanLyThuVien()
    {
        taoFile();
        docSach();
        docBanDoc();
        docPhieuMuon();
    }

    // Tao file neu chua co
    void taoFile()
    {
        ifstream f1("Admin.txt");
        if (!f1)
        {
            ofstream f("Admin.txt");
            f << "admin 123\n";
            f.close();
        }
        else
        {
            f1.close();
        }

        ifstream f2("BanDoc.txt");
        if (!f2)
        {
            ofstream f("BanDoc.txt");
            f << "BD01|Nguyen Van A|01/01/2026\n";
            f.close();
        }
        else
        {
            f2.close();
        }

        ifstream f3("Sach.txt");
        if (!f3)
        {
            ofstream f("Sach.txt");
            f.close();
        }
        else
        {
            f3.close();
        }

        ifstream f4("PhieuMuon.txt");
        if (!f4)
        {
            ofstream f("PhieuMuon.txt");
            f.close();
        }
        else
        {
            f4.close();
        }
    }

    // ==================== DOC FILE SACH ====================

    void docSach()
    {
        dsSach.clear();

        ifstream file("Sach.txt");
        string line;

        while (getline(file, line))
        {
            if (line == "")
                continue;

            vector<string> data = split(line, '|');

            if (data.size() >= 9)
            {
                Sach sach;

                sach.setMaSach(data[0]);
                sach.setTenSach(data[1]);
                sach.setTacGia(data[2]);
                sach.setNxb(data[3]);

                double gia;
                stringstream ssGia(data[4]);
                ssGia >> gia;
                sach.setGiaBan(gia);

                int nam;
                stringstream ssNam(data[5]);
                ssNam >> nam;
                sach.setNamPhatHanh(nam);

                int trang;
                stringstream ssTrang(data[6]);
                ssTrang >> trang;
                sach.setSoTrang(trang);

                sach.setNgayNhapKho(data[7]);

                int tt;
                stringstream ssTT(data[8]);
                ssTT >> tt;
                sach.setTinhTrang(tt);

                dsSach.push_back(sach);
            }
        }

        file.close();
    }

    void ghiSach()
    {
        ofstream file("Sach.txt");

        for (int i = 0; i < (int)dsSach.size(); i++)
        {
            file << dsSach[i].getMaSach() << "|"
                 << dsSach[i].getTenSach() << "|"
                 << dsSach[i].getTacGia() << "|"
                 << dsSach[i].getNxb() << "|"
                 << fixed << setprecision(0) << dsSach[i].getGiaBan() << "|"
                 << dsSach[i].getNamPhatHanh() << "|"
                 << dsSach[i].getSoTrang() << "|"
                 << dsSach[i].getNgayNhapKho() << "|"
                 << dsSach[i].getTinhTrang() << "\n";
        }

        file.close();
    }

    // ==================== DOC FILE BAN DOC ====================

    void docBanDoc()
    {
        dsBanDoc.clear();

        ifstream file("BanDoc.txt");
        string line;

        while (getline(file, line))
        {
            if (line == "")
                continue;

            vector<string> data = split(line, '|');

            if (data.size() >= 3)
            {
                BanDoc bd;

                bd.setMaBD(data[0]);
                bd.setHoTen(data[1]);
                bd.setNgayDK(data[2]);

                dsBanDoc.push_back(bd);
            }
        }

        file.close();
    }

    // ==================== DOC FILE PHIEU MUON ====================

    void docPhieuMuon()
    {
        dsPhieuMuon.clear();

        ifstream file("PhieuMuon.txt");
        string line;

        while (getline(file, line))
        {
            if (line == "")
                continue;

            vector<string> data = split(line, '|');

            if (data.size() >= 6)
            {
                PhieuMuon phieu;

                int so;
                stringstream ssSo(data[0]);
                ssSo >> so;
                phieu.setSoPhieu(so);

                phieu.setMaBD(data[1]);
                phieu.setMaSach(data[2]);
                phieu.setNgayMuon(data[3]);
                phieu.setNgayTra(data[4]);

                int tt;
                stringstream ssTT(data[5]);
                ssTT >> tt;
                phieu.setTinhTrang(tt);

                dsPhieuMuon.push_back(phieu);
            }
        }

        file.close();
    }

    void ghiPhieuMuon()
    {
        ofstream file("PhieuMuon.txt");

        for (int i = 0; i < (int)dsPhieuMuon.size(); i++)
        {
            file << dsPhieuMuon[i].getSoPhieu() << "|"
                 << dsPhieuMuon[i].getMaBD() << "|"
                 << dsPhieuMuon[i].getMaSach() << "|"
                 << dsPhieuMuon[i].getNgayMuon() << "|"
                 << dsPhieuMuon[i].getNgayTra() << "|"
                 << dsPhieuMuon[i].getTinhTrang() << "\n";
        }

        file.close();
    }

    // ==================== HIEN THI SACH ====================

    void hienThiSach()
    {
        if (dsSach.empty())
        {
            printEffect("\n  [!] Kho sach hien dang trong!\n", COLOR_LOI);
            return;
        }

        setColor(COLOR_VIEN);
        cout << "\n  " << char(201) << string(WIDTH_FRAME, char(205)) << char(187) << "\n";

        cout << "  " << char(186) << " ";

        setColor(COLOR_TIEU_DE);

        cout << left
             << setw(10) << "Ma Sach"
             << setw(25) << "Ten Sach"
             << setw(20) << "Tac Gia"
             << setw(10) << "Nam XB"
             << setw(15) << "Tinh Trang"
             << right << setw(24) << "Ngay Nhap";

        setColor(COLOR_VIEN);
        cout << " " << char(186) << "\n";

        cout << "  " << char(204)
             << string(WIDTH_FRAME, char(205))
             << char(185) << "\n";

        for (int i = 0; i < (int)dsSach.size(); i++)
        {
            setColor(COLOR_VIEN);
            cout << "  " << char(186) << " ";

            setColor(COLOR_TEXT);

            cout << left
                 << setw(10) << dsSach[i].getMaSach()
                 << setw(25) << dsSach[i].getTenSach()
                 << setw(20) << dsSach[i].getTacGia()
                 << setw(10) << dsSach[i].getNamPhatHanh();

            if (dsSach[i].getTinhTrang() == 0)
            {
                setColor(COLOR_CHON);
                cout << left << setw(15) << "San sang";
            }
            else
            {
                setColor(COLOR_LOI);
                cout << left << setw(15)
                     << ("Muon (Phieu " + toStr(dsSach[i].getTinhTrang()) + ")");
            }

            setColor(COLOR_TEXT);
            cout << right << setw(24) << dsSach[i].getNgayNhapKho();

            setColor(COLOR_VIEN);
            cout << " " << char(186) << "\n";
        }

        cout << "  " << char(200)
             << string(WIDTH_FRAME, char(205))
             << char(188) << "\n";
    }

    // ==================== THEM SACH ====================

    void themSach()
    {
        string temp;
        double gia;
        int nam, soTrang;

        setColor(COLOR_VIEN);
        cout << "\n  " << char(204) << char(205)
             << " Nhap Ma sach: ";

        setColor(COLOR_TEXT);
        getline(cin, temp);

        for (int i = 0; i < (int)dsSach.size(); i++)
        {
            if (dsSach[i].getMaSach() == temp)
            {
                printEffect("  [!] Ma sach da ton tai. Khong the them!\n", COLOR_LOI);
                return;
            }
        }

        Sach sach;
        sach.setMaSach(temp);

        setColor(COLOR_VIEN);
        cout << "  " << char(204) << char(205)
             << " Nhap Ten sach: ";
        setColor(COLOR_TEXT);
        getline(cin, temp);
        sach.setTenSach(temp);

        setColor(COLOR_VIEN);
        cout << "  " << char(204) << char(205)
             << " Nhap Tac gia: ";
        setColor(COLOR_TEXT);
        getline(cin, temp);
        sach.setTacGia(temp);

        setColor(COLOR_VIEN);
        cout << "  " << char(204) << char(205)
             << " Nhap NXB: ";
        setColor(COLOR_TEXT);
        getline(cin, temp);
        sach.setNxb(temp);

        setColor(COLOR_VIEN);
        cout << "  " << char(204) << char(205)
             << " Nhap Gia ban: ";
        setColor(COLOR_TEXT);
        cin >> gia;
        sach.setGiaBan(gia);

        setColor(COLOR_VIEN);
        cout << "  " << char(204) << char(205)
             << " Nhap Nam phat hanh: ";
        setColor(COLOR_TEXT);
        cin >> nam;
        sach.setNamPhatHanh(nam);

        setColor(COLOR_VIEN);
        cout << "  " << char(204) << char(205)
             << " Nhap So trang: ";
        setColor(COLOR_TEXT);
        cin >> soTrang;
        sach.setSoTrang(soTrang);

        cin.ignore();

        sach.setNgayNhapKho(getNgayHienTai());
        sach.setTinhTrang(0);

        dsSach.push_back(sach);
        ghiSach();

        printEffect("\n  => Them sach vao he thong thanh cong!\n", COLOR_CHON);
    }

    // ==================== XOA SACH ====================

    void xoaSach()
    {
        string ma;

        setColor(COLOR_VIEN);
        cout << "\n  " << char(204) << char(205)
             << " Nhap Ma sach can xoa: ";

        setColor(COLOR_TEXT);
        getline(cin, ma);

        for (int i = 0; i < (int)dsSach.size(); i++)
        {
            if (dsSach[i].getMaSach() == ma)
            {
                if (dsSach[i].getTinhTrang() != 0)
                {
                    printEffect(
                        "  [!] Khong the xoa! Sach nay dang duoc muon.\n",
                        COLOR_LOI
                    );
                    return;
                }

                dsSach.erase(dsSach.begin() + i);
                ghiSach();

                printEffect(
                    "  => Da xoa sach thanh cong!\n",
                    COLOR_CHON
                );
                return;
            }
        }

        printEffect(
            "  [!] Khong tim thay Ma sach trong he thong!\n",
            COLOR_LOI
        );
    }

    // ==================== HIEN THI PHIEU MUON ====================

    void hienThiPhieuMuon()
    {
        if (dsPhieuMuon.empty())
        {
            printEffect(
                "\n  [!] Chua co phieu muon nao trong he thong!\n",
                COLOR_LOI
            );
            return;
        }

        setColor(COLOR_VIEN);

        cout << "\n  " << char(201)
             << string(91, char(205))
             << char(187) << "\n";

        cout << "  " << char(186) << " ";

        setColor(COLOR_TIEU_DE);

        cout << left
             << setw(10) << "So Phieu"
             << setw(15) << "Ma BD"
             << setw(15) << "Ma Sach"
             << setw(15) << "Ngay Muon"
             << setw(15) << "Ngay Tra"
             << right << setw(19) << "Tinh Trang";

        setColor(COLOR_VIEN);
        cout << " " << char(186) << "\n";

        cout << "  " << char(204)
             << string(91, char(205))
             << char(185) << "\n";

        for (int i = 0; i < (int)dsPhieuMuon.size(); i++)
        {
            setColor(COLOR_VIEN);
            cout << "  " << char(186) << " ";

            setColor(COLOR_TEXT);

            cout << left
                 << setw(10) << dsPhieuMuon[i].getSoPhieu()
                 << setw(15) << dsPhieuMuon[i].getMaBD()
                 << setw(15) << dsPhieuMuon[i].getMaSach()
                 << setw(15) << dsPhieuMuon[i].getNgayMuon()
                 << setw(15) << dsPhieuMuon[i].getNgayTra();

            if (dsPhieuMuon[i].getTinhTrang() == 1)
            {
                setColor(COLOR_LOI);
                cout << right << setw(19) << "Dang muon";
            }
            else
            {
                setColor(COLOR_CHON);
                cout << right << setw(19) << "Da tra";
            }

            setColor(COLOR_VIEN);
            cout << " " << char(186) << "\n";
        }

        cout << "  " << char(200)
             << string(91, char(205))
             << char(188) << "\n";
    }

    // ==================== MUON SACH ====================

    void muonSach()
    {
        string maSach, maBD;

        setColor(COLOR_VIEN);
        cout << "\n  " << char(204) << char(205)
             << " Nhap Ma sach muon muon: ";

        setColor(COLOR_TEXT);
        getline(cin, maSach);

        int viTriSach = -1;

        for (int i = 0; i < (int)dsSach.size(); i++)
        {
            if (dsSach[i].getMaSach() == maSach)
            {
                viTriSach = i;
                break;
            }
        }

        if (viTriSach == -1)
        {
            printEffect("  [!] Khong tim thay Ma sach!\n", COLOR_LOI);
            return;
        }

        if (dsSach[viTriSach].getTinhTrang() != 0)
        {
            printEffect(
                "  [!] Sach nay hien dang duoc muon boi nguoi khac!\n",
                COLOR_LOI
            );
            return;
        }

        setColor(COLOR_VIEN);
        cout << "  " << char(204) << char(205)
             << " Nhap Ma ban doc: ";

        setColor(COLOR_TEXT);
        getline(cin, maBD);

        bool timThay = false;

        for (int i = 0; i < (int)dsBanDoc.size(); i++)
        {
            if (dsBanDoc[i].getMaBD() == maBD)
            {
                timThay = true;
                break;
            }
        }

        if (!timThay)
        {
            printEffect(
                "  [!] Ma ban doc khong ton tai!\n",
                COLOR_LOI
            );
            return;
        }

        PhieuMuon phieu;

        int soPhieu = 1;

        if (!dsPhieuMuon.empty())
        {
            soPhieu = dsPhieuMuon.back().getSoPhieu() + 1;
        }

        phieu.setSoPhieu(soPhieu);
        phieu.setMaBD(maBD);
        phieu.setMaSach(maSach);
        phieu.setNgayMuon(getNgayHienTai());
        phieu.setNgayTra(getNgayTra());
        phieu.setTinhTrang(1);

        dsPhieuMuon.push_back(phieu);

        // Luu so phieu vao tinh trang cua sach
        dsSach[viTriSach].setTinhTrang(soPhieu);

        ghiPhieuMuon();
        ghiSach();

        printEffect(
            "\n  => Tao Phieu Muon thanh cong! So Phieu: "
            + toStr(phieu.getSoPhieu()) + "\n",
            COLOR_CHON
        );
    }

    // ==================== TRA SACH ====================

    void traSach()
    {
        int soPhieu;

        setColor(COLOR_VIEN);
        cout << "\n  " << char(204) << char(205)
             << " Nhap So phieu de tra sach: ";

        setColor(COLOR_TEXT);
        cin >> soPhieu;
        cin.ignore();

        int viTriPhieu = -1;

        for (int i = 0; i < (int)dsPhieuMuon.size(); i++)
        {
            if (dsPhieuMuon[i].getSoPhieu() == soPhieu)
            {
                viTriPhieu = i;
                break;
            }
        }

        if (viTriPhieu == -1)
        {
            printEffect(
                "  [!] Khong tim thay So phieu nay!\n",
                COLOR_LOI
            );
            return;
        }

        if (dsPhieuMuon[viTriPhieu].getTinhTrang() == 0)
        {
            printEffect(
                "  [!] Sach cua phieu nay da duoc tra truoc do!\n",
                COLOR_LOI
            );
            return;
        }

        string maSach = dsPhieuMuon[viTriPhieu].getMaSach();

        for (int i = 0; i < (int)dsSach.size(); i++)
        {
            if (dsSach[i].getMaSach() == maSach)
            {
                dsSach[i].setTinhTrang(0);
                break;
            }
        }

        dsPhieuMuon[viTriPhieu].setTinhTrang(0);

        ghiPhieuMuon();
        ghiSach();

        printEffect(
            "\n  => Tra sach thanh cong! Da cap nhat he thong.\n",
            COLOR_CHON
        );
    }
};

// ==================== DANG NHAP ====================

bool dangNhap()
{
    ifstream file("Admin.txt");

    string userDung;
    string passDung;

    file >> userDung >> passDung;
    file.close();

    int soLan = 0;

    while (soLan < 3)
    {
        system("cls");

        setColor(COLOR_TIEU_DE);

        cout << "\n\t***********************************";
        cout << "\n\t*       DANG NHAP HE THONG        *";
        cout << "\n\t***********************************\n\n";

        string user;
        string pass;

        setColor(COLOR_CHON);
        cout << "\tUser:     ";

        setColor(COLOR_TEXT);
        getline(cin, user);

        setColor(COLOR_CHON);
        cout << "\n\tPassword: ";

        setColor(COLOR_TEXT);

        while (true)
        {
            char c = _getch();

            if (c == 27)
            {
                printEffect(
                    "\n\n\tDa an ESC. Thoat he thong!\n",
                    COLOR_LOI
                );
                return false;
            }

            if (c == 13)
            {
                break;
            }

            if (c == 8)
            {
                if (!pass.empty())
                {
                    cout << "\b \b";
                    pass.erase(pass.length() - 1);
                }
            }
            else
            {
                pass += c;
                cout << "*";
            }
        }

        if (user == userDung && pass == passDung)
        {
            printEffect(
                "\n\n\tDang nhap thanh cong!\n",
                COLOR_CHON,
                15
            );

            Sleep(500);
            return true;
        }

        soLan++;

        printEffect(
            "\n\n\tSai User hoac Password! (Con "
            + toStr(3 - soLan) + " lan thu)\n",
            COLOR_LOI
        );

        system("pause");
    }

    return false;
}

// ==================== VE MENU ====================

void veMenu(string tieuDe, vector<string> luaChon)
{
    system("cls");

    setColor(COLOR_VIEN);

    cout << "\n  " << char(201)
         << string(44, char(205))
         << char(187) << "\n";

    cout << "  " << char(186);

    setColor(COLOR_TIEU_DE);

    int trai = (44 - (int)tieuDe.length()) / 2;
    int phai = 44 - (int)tieuDe.length() - trai;

    cout << string(trai, ' ')
         << tieuDe
         << string(phai, ' ');

    setColor(COLOR_VIEN);

    cout << char(186) << "\n";

    cout << "  " << char(204)
         << string(44, char(205))
         << char(185) << "\n";

    for (int i = 0; i < (int)luaChon.size(); i++)
    {
        setColor(COLOR_VIEN);
        cout << "  " << char(186) << " ";

        if (i == (int)luaChon.size() - 1)
        {
            setColor(COLOR_LOI);
        }
        else
        {
            setColor(COLOR_TIEU_DE);
        }

        string stt = toStr(i + 1) + ". ";

        cout << stt;

        setColor(COLOR_TEXT);

        int khoangTrong = 44 - 1 - (int)stt.length();

        cout << left << setw(khoangTrong) << luaChon[i];

        setColor(COLOR_VIEN);
        cout << char(186) << "\n";
    }

    cout << "  " << char(200)
         << string(44, char(205))
         << char(188) << "\n\n";

    printEffect(
        "  >> Nhap lua chon: ",
        COLOR_TIEU_DE,
        0
    );

    setColor(COLOR_TEXT);
}

// ==================== MAIN ====================

int main()
{
    SetConsoleOutputCP(437);

    QuanLyThuVien ql;

    if (!dangNhap())
    {
        return 0;
    }

    int chonChinh;

    do
    {
        vector<string> menuChinh;

        menuChinh.push_back("Quan ly sach");
        menuChinh.push_back("Quan ly phieu muon");
        menuChinh.push_back("Thoat chuong trinh");

        veMenu(
            "HE THONG QUAN LY THU VIEN",
            menuChinh
        );

        cin >> chonChinh;
        cin.ignore();

        // ================= MENU SACH =================

        if (chonChinh == 1)
        {
            int chonSach;

            do
            {
                vector<string> menuSach;

                menuSach.push_back("Hien thi thong tin sach");
                menuSach.push_back("Them sach moi");
                menuSach.push_back("Xoa sach");
                menuSach.push_back("Quay lai menu chinh");

                veMenu(
                    "QUAN LY SACH",
                    menuSach
                );

                cin >> chonSach;
                cin.ignore();

                switch (chonSach)
                {
                    case 1:
                        ql.hienThiSach();
                        break;

                    case 2:
                        ql.themSach();
                        break;

                    case 3:
                        ql.xoaSach();
                        break;

                    case 4:
                        break;

                    default:
                        printEffect(
                            "  [!] Lua chon sai!\n",
                            COLOR_LOI
                        );
                }

                if (chonSach != 4)
                {
                    cout << "\n  ";
                    system("pause");
                }

            } while (chonSach != 4);
        }

        // ================= MENU PHIEU MUON =================

        else if (chonChinh == 2)
        {
            int chonPhieu;

            do
            {
                vector<string> menuPhieu;

                menuPhieu.push_back("Hien thi thong tin phieu muon");
                menuPhieu.push_back("Muon sach (Tao phieu)");
                menuPhieu.push_back("Tra sach");
                menuPhieu.push_back("Quay lai menu chinh");

                veMenu(
                    "QUAN LY PHIEU MUON",
                    menuPhieu
                );

                cin >> chonPhieu;
                cin.ignore();

                switch (chonPhieu)
                {
                    case 1:
                        ql.hienThiPhieuMuon();
                        break;

                    case 2:
                        ql.muonSach();
                        break;

                    case 3:
                        ql.traSach();
                        break;

                    case 4:
                        break;

                    default:
                        printEffect(
                            "  [!] Lua chon sai!\n",
                            COLOR_LOI
                        );
                }

                if (chonPhieu != 4)
                {
                    cout << "\n  ";
                    system("pause");
                }

            } while (chonPhieu != 4);
        }

    } while (chonChinh != 3);

    printEffect(
        "\n  DANG THOAT HE THONG...\n  TAM BIET!\n",
        COLOR_CHON,
        20
    );

    return 0;
}
