//#include <sys/time.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>

#include <stdio.h>
#include <time.h>

#include <iostream>
#include <Windows.h>
using namespace std;

using namespace std;
//
//DWORD CopyToClipboard(std::wstring str)
//{
//    DWORD len = str.size();
//    HGLOBAL hdst;
//    LPWSTR dst;
//
//    // Allocate string for cwd
//    hdst = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, (len + 1) * sizeof(WCHAR));
//    dst = (LPWSTR)GlobalLock(hdst);
//    memcpy(dst, str.c_str(), len * sizeof(WCHAR));
//    dst[len] = 0;
//    GlobalUnlock(hdst);
//
//    // Set clipboard data
//    if (!OpenClipboard(NULL)) return GetLastError();
//    EmptyClipboard();
//    if (!SetClipboardData(CF_UNICODETEXT, hdst)) 
//        return GetLastError();
//    CloseClipboard();
//
//    return 0;
//}

//const int kAverageSpeed = 10 * 1024 * 1024;   // 10Mbps = 10485760 bps


//std::wstring toLeadingZeroStrW(int t)
//{
//	std::wstringstream wss;
//    wss << std::setw(2) << std::setfill('0') << t;
//	return wss.str();
//}

#include <ctime>


int main()
{

    /*1ms == 0.001  sec
    0.000 000 001  sec
    0.000 000 1  sec*/

    // http://stackoverflow.com/questions/1695288/getting-the-current-time-in-milliseconds-from-the-system-clock-in-windows
    FILETIME ft_now;
	GetSystemTimeAsFileTime(&ft_now);
	LONGLONG ll_now = (LONGLONG)ft_now.dwLowDateTime + ((LONGLONG)(ft_now.dwHighDateTime) << 32LL);
    printf("%f\n", (ll_now - 116444736000000000LL) * 0.0000001 );


    //time_t seconds;

    //seconds = time (NULL);

    //printf("%ld seconds since January 1, 1970", seconds);

    
    /*long double s = static_cast<long double>(seconds);
    printf ("%f\n", s);*/

    ////std::time_t result = std::time(NULL);
    ////std::cout << result << " seconds since the Epoch\n";

    ////time_t seconds_past_epoch = time(0);

    ////double seconds = seconds_past_epoch;

    ////cout << seconds; 

    //time_t now;
    //long double seconds;

    //time(&now);

    //struct tm newyear;
    //newyear = *localtime(&now);

    //cout << newyear.tm_year << endl;
    //cout << newyear.tm_hour << endl;
    //cout << newyear.tm_min << endl;
    //cout << newyear.tm_sec << endl;
    //cout << newyear.tm_mon << endl;
    //cout << newyear.tm_mday << endl;
    ///*newyear.tm_year -= 1900;
    //newyear.tm_hour = 0; 
    //newyear.tm_min = 0; 
    //newyear.tm_sec = 0;
    //newyear.tm_mon = 0;
    //newyear.tm_mday = 0;*/


    //long double test = newyear.tm_sec + newyear.tm_min*60.0 + newyear.tm_hour*3600.0 + 
    //newyear.tm_yday*86400.0 + (newyear.tm_year-70.0)*31536000.0 + ((newyear.tm_year-69.0)/4.0)*86400.0 -
    //((newyear.tm_year-1.0)/100.0)*86400.0 + ((newyear.tm_year+299.0)/400.0)*86400.0;

    //printf("%f\n", test);
    
    
  //time_t now;
  //long double seconds;

  //time(&now);  /* get current time; same as: now = time(NULL)  */

  /*struct tm newyear;
  newyear = *localtime(&now);*/

  //newyear.tm_year -= 1900;
  ////newyear.tm_hour = 0; 
  ////newyear.tm_min = 0; 
  ////newyear.tm_sec = 0;
  ////newyear.tm_mon = 0;
  ////newyear.tm_mday = 0;

  //seconds = difftime(now, mktime(&newyear));

  //printf ("%ld seconds since new year in the current timezone.\n", seconds);


    

    //int filesize_in_bits = 9448320 * 8;    // change the filesize from bytes to bits.
    //int downloading_time_in_sec = filesize_in_bits / kAverageSpeed;

    //int hours = downloading_time_in_sec / 3600;        // Hour component
    //int minutes = (downloading_time_in_sec % 3600) / 60;    // Minute component
    //int seconds = downloading_time_in_sec % 60;             // Second component

 //   std::stringstream ss;
 //   ss << std::setw(2) << std::setfill('0') << 2 << "\n";
 //   std::string s2(ss.str());
 //   std::cout << s2;

 //   FILE* fp = stdin;
 //   int data = 0;
 //   char buffer[12] = {0};
 //   int b = getchar();

 //   gets_s(buffer, sizeof(buffer));
 //   //scanf_s("%d", &data);


	//int a = getchar();
	//getchar();
	//getchar();
	//getchar();
	//getchar();
	//getchar();
 //   getchar();
 //   getchar();

    //int array[5];
    //printf("%d\n", sizeof(array));
    //printf("%d\n", 20);





    //cout << dest << endl;

    //toLeadingZeroStrW(seconds);

    /*wchar_t mins[2];
    sprintf(mins, "%02d", minutes);

    wchar_t mins[2];
    sprintf(mins, "%02d", minutes);

    wchar_t secs[2];
    sprintf(secs, "%02d", seconds);

    if (hours == 0)
        std::cout << L"00:" + toStrW(mins) + L":" + toStrW(secs) << std::endl;
    else
        std::cout << toStrW(hours) + L"00:" + toStrW(mins) + L":" + toStrW(secs) << std::endl;*/



    /*std::wstring wstr = L"1212 1212 2334";
    CopyToClipboard(wstr);*/

    return 0;
}



//#include <iostream>
//#include <string>
//#include <windows.h>
//
//void toClipboard(const std::wstring &s){
//	OpenClipboard(0);
//	EmptyClipboard();
//	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE, s.size()+1);
//	if (!hg){
//		CloseClipboard();
//		return;
//	}
//	memcpy(GlobalLock(hg), s.c_str(), s.size()+1);
//	GlobalUnlock(hg);
//	SetClipboardData(CF_TEXT,hg);
//	CloseClipboard();
//	GlobalFree(hg);
//}
//
//int main(void)
//{
//    std::wstring w = L"some wstring";
//    toClipboard(w);
//}