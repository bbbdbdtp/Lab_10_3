#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_3/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestFindFriendByPhoneNumber)
        {
            Friend friends[1];
            friends[0].fullName = "Brown Emily";
            friends[0].phoneNumber = "+555666777";
            friends[0].birthDate[0] = 10;
            friends[0].birthDate[1] = 3;
            friends[0].birthDate[2] = 1995;
            int size = 1;

            string testPhoneNumber = "+555666777";
            stringstream buffer;
            streambuf* oldOutput = cout.rdbuf(buffer.rdbuf());

            findFriendByPhoneNumber(friends, size, testPhoneNumber);

            string output = buffer.str();
            Assert::AreEqual(findFriendByPhoneNumber(friends, size, testPhoneNumber), testPhoneNumber);

            cout.rdbuf(oldOutput);
        }
    };
}