#pragma once
#include<iostream>
#include"clsDate.h";
#include<string>
class clsUtil
{
public:
	static enum enCharType
	{
		SmallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4, SpecialCharacter = 5
	};

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}

	//--------------------------------------------------------------------------------

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);

		}
		switch (CharType)
		{
		case enCharType::CapitalLetter:
		{	return char(RandomNumber(65, 90));
		break;
		}
		case enCharType::SmallLetter:
		{	return char(RandomNumber(97, 122));
		break;
		}
		case enCharType::SpecialCharacter:
		{	return char(RandomNumber(33, 47));
		break;
		}
		case enCharType::Digit:
		{	return char(RandomNumber(48, 57));
		break;
		}
		default:
			return char(RandomNumber(65, 90));
			break;
		}
	}
	static string GenerateWord(enCharType charType, short Lenght)
	{
		string word = "";
		for (int i = 1; i <= Lenght; i++)
		{
			word += GetRandomCharacter(charType);
		}
		return word;
	}
	static string GenerateKey(enCharType charType)
	{
		string key = "";
		key = key + GenerateWord(charType, 4) + '_';
		key = key + GenerateWord(charType, 4) + '_';
		key = key + GenerateWord(charType, 4) + '_';
		key = key + GenerateWord(charType, 4);
		return key;
	}
	static void GenerateKeys(int NumberOfKeys, enCharType CharType)
	{
		for (int i = 0; i < NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}

	}

	//--------------------------------------------------------------------------------

	static  void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static  void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);

	}

	//--------------------------------------------------------------------------------
	static void shuffelArry(int Arry[], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			swap(Arry[RandomNumber(1, Length) - 1], Arry[RandomNumber(1, Length) - 1]);
		}
	}
	static void shuffelArry(string Arry[], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			swap(Arry[RandomNumber(1, Length) - 1], Arry[RandomNumber(1, Length) - 1]);
		}
	}

	//--------------------------------------------------------------------------------

	static void FillArryWithRandomNumbers(int Arry[], int ArrayLenght, int From, int To)
	{
		for (int i = 0; i < ArrayLenght; i++)
		{
			Arry[i] = RandomNumber(From, To);
		}
	}
	static void FillArryWithRandomWords(string Arry[], int ArrayLenght, enCharType CharType, int WordLength)
	{
		for (int i = 0; i < ArrayLenght; i++)
		{
			Arry[i] = GenerateWord(CharType, WordLength);
		}
	}
	static void FillArryWithRandomKeys(string Arry[], int ArrayLenght, enCharType CharType)
	{
		for (int i = 0; i < ArrayLenght; i++)
		{
			Arry[i] = GenerateKey(CharType);
		}
	}

	//--------------------------------------------------------------------------------

	static string Taps(int NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;
	}

	//--------------------------------------------------------------------------------

	static string EncryptText(string text, short Key)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char((int)text[i] + Key);
		}
		return text;
	}
	static string DecryptText(string text, short key)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char((int)text[i] - key);
		}
		return text;

	}

	//--------------------------------------------------------------------------------

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}
};

