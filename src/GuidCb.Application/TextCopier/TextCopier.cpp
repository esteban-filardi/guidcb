#include "pch.h"
#include "TextCopier.h"

int TextCopier::CopyText(const char* text, bool& retflag)
{
    retflag = true;
    if (!OpenClipboard(NULL)) {
        std::cerr << "Error while opening the clipboard";
        return 1;
    }


    EmptyClipboard();

    const size_t textLength = strlen(text) + 1;
    HGLOBAL textMemoryHandler = GlobalAlloc(GMEM_MOVEABLE, textLength * sizeof(TCHAR));

    if (textMemoryHandler == NULL) {
        CloseClipboard();
        return -1;
    }

    LPVOID textMemoryLock = GlobalLock(textMemoryHandler);

    if (textMemoryLock == NULL) {
        CloseClipboard();
        return -1;
    }

    memcpy(textMemoryLock, text, textLength * sizeof(TCHAR));

    GlobalUnlock(textMemoryHandler);

    SetClipboardData(CF_TEXT, textMemoryHandler);

    CloseClipboard();
    retflag = false;
    return {};
}
