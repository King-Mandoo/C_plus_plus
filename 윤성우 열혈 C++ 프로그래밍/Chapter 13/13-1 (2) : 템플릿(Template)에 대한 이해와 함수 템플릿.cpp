🟢 함수 템플릿의 특수화(Specialization)

#include <iostream>
using namespace std;

template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	cout << Max(11, 15) << endl;            // 15 출력
	cout << Max('T', 'Q') << endl;          // T  출력
	cout << Max(3.5, 7.5) << endl;          // 7.5 출력
	cout << Max("Simple", "Ace") << endl;   // Simple 출력  👈👈 주의 깊게 보기
	
	return 0;
}                            ✅ cout << Max("Simple", "Ace") << endl; <-- 이 문장은 제대로된 비교 결과를 반환할 수 없다.
                                왜냐하면 "Simple"과 "Ace"는 const char* 형이므로 그저 단순히 주소 값의 비교결과가 반환되기 때문이다.
  
                                따라서 문자열의 길이비교 또는 사전편찬 순서의 비교가 목적이라면 따로 템플릿 함수를 구성해야 한다.
  
  
template<> 
const char* Max(const char* a, const char* b)   
{
	return strlen(a) > strlen(b) ? a : b;
}
  
     🎈🎈 "const char* 형 함수는 내가 이렇게 제시를 하니, const char* 형 템플릿 함수가 필요한 경우에는 별도로 만들지 말고 이것을 써라!"

---------------------------------------------------------------------
  
#include <iostream>
using namespace std;

template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<>
const char* Max(const char* a, const char* b)  // 문자열 길이 비교 함수
{
	return strlen(a) > strlen(b) ? a : b;
}

template<>
char* Max(char* a, char* b)   // 사전편찬 순서의 비교 함수
{
	return strcmp(a, b) < 0 ? a : b;
}

int main()
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Ace") << endl;

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;
	
	return 0;
}
  
