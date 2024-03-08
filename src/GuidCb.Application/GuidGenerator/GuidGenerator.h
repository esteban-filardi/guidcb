#pragma once

class GuidGenerator
{

	public:
		const char* GenerateGuid();
	private:
		static const char* ConvertGuidToConstCString(GUID guid);
		static const char* LowerCaseString(const char* str);
};
