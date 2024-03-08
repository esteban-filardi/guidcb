#include "GuidGenerator.h"

const char* GuidGenerator::GenerateGuid()
{
    GUID gidReference;
    HRESULT hCreateGuid = CoCreateGuid(&gidReference);

    const char * guidCString = ConvertGuidToConstCString(gidReference);

    // Most of the time, GUIDs are represented in lowercase
    return LowerCaseString(guidCString);
}

const char* GuidGenerator::ConvertGuidToConstCString(GUID guid)
{
    char* guidString = new char[40];
    sprintf_s(guidString, 40, "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
        guid.Data1, guid.Data2, guid.Data3,
        guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
        guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
    return guidString;

}

const char* GuidGenerator::LowerCaseString(const char* str)
{
	char* lowerCaseString = new char[strlen(str) + 1];
    for (int i = 0; i < strlen(str); i++)
    {
		lowerCaseString[i] = tolower(str[i]);
	}
	lowerCaseString[strlen(str)] = '\0';
	return lowerCaseString;
}