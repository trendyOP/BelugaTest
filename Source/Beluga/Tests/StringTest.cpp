#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	// 생성, 대입
	{
		FString strChar("char");
		FString strWChar(L"wchar");
		FString strTChar(TEXT("wchar"));

		strChar = "char";
		strWChar = "wchar";
		strTChar = TEXT("wchar");
	}

	// Printf
	{
		TestEqual(TEXT("Printf"), FString::Printf(TEXT("%d %f %s"), 123, 1.0f, TEXT("string")), TEXT("123 1.000000 string"));
	}

	// Format
	{
		{
			FStringFormatNamedArguments NamedArgs;
			NamedArgs.Add(TEXT("First"), 123);
			NamedArgs.Add(TEXT("Second"), 1.0f);
			NamedArgs.Add(TEXT("Third"), TEXT("string"));

			TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
		}
		
		{
			FStringFormatOrderedArguments OrderedArgs;
			OrderedArgs.Add(123);
			OrderedArgs.Add(1.0f);
			OrderedArgs.Add(TEXT("string"));
			
			TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));
		}
	}

	FString strApple(TEXT("Apple"));
	FString strBanana(TEXT("Banana"));

	// Operators
	{
		// []
		{
			TestEqual(TEXT("Operator []"), strApple[0], L'A');
		}

		// < >
		{
			TestTrue(TEXT("Operator <"), strApple < strBanana);
		}
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaNameTest::RunTest(const FString& Parameters)
{
	FName Name1 = FName(TEXT("TestFName"));
	FName Name2 = FName(TEXT("TESTFNAME"));
	FName Name3 = FName(TEXT("TestFName3"));

	TestTrue(TEXT("대소문자 구분 안함 1"), Name1 == Name2);
	
	TestFalse(TEXT("대소문자 구분 안함 2"), Name1 == Name3);

	return true;
}
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTextTest, "Beluga.Text", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
bool FBelugaTextTest::RunTest(const FString& Parameters)
{
#define LOCTEXT_NAMESPACE "MyNameSpace"
	FText constFTextHelloworld = NSLOCTEXT("MyOtherNameSpace", "HelloWorld", "Hello World!");
	const FText GoodbyeWorld = LOCTEXT("GoodbyeWorld", "Goodbye World!");
#undef LOCTEXT_NAMESPACE
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaArrayTest, "Beluga.Array", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
bool FBelugaArrayTest::RunTest(const FString& Parameters)
{
	TArray<int32> IntArray;
	IntArray.Init(10, 3);
	FString Elem1 = StrArray[0];
	FString Elem2 = StrArray[2];
	TestTrue(TEXT("앞뒤가 같은 숫자인가 1"), Elem1 != Elem2);
	TestFalse(TEXT("앞뒤가 같은 숫자인가 2"), Elem1 != Elem2);

}