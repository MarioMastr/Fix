#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/VideoOptionsLayer.hpp>

#if defined(GEODE_IS_MACOS)
#include <mach/mach_time.h>
// #elif defined(GEODE_IS_ANDROID)
// #include <time.h>
#endif

uint64_t currentTime() // multiplatform time getter
{
#if defined(GEODE_IS_WINDOWS)
    LARGE_INTEGER large_integer;
    QueryPerformanceCounter(&large_integer);
    return large_integer.QuadPart;
#elif defined(GEODE_IS_MACOS)
    return mach_absolute_time();
// #elif defined(GEODE_IS_ANDROID)
    // struct timespec now;
	// clock_gettime(CLOCK_MONOTONIC, &now);
    // return now.tv_nsec;
#endif
}

void openLink(const char *link) // multiplatform weblink opener
{
#if defined(GEODE_IS_WINDOWS)
    ShellExecute(0, 0, link, 0, 0, SW_SHOW);
#elif defined(GEODE_IS_MACOS)
    system(("open " + std::string(link)).c_str());
// #elif defined(GEODE_IS_ANDROID)
    // Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(link));
    // startActivity(browserIntent);
#endif
}

bool checkSuffix(uint64_t A, uint64_t B) // check whether number end in digit
{
    // Convert numbers into strings
    std::string s1 = std::to_string(A);
    std::string s2 = std::to_string(B);

    // Find the lengths of strings
    // s1 and s2
    uint64_t n1 = s1.length();
    uint64_t n2 = s2.length();

    // Base Case
    if (n1 < n2) {
        return false;
    }

    // Traverse the strings s1 & s2
    for (uint64_t i = 0; i < n2; i++) {

        // If at any index characters
        // are unequals then return false
        if (s1[n1 - i - 1] != s2[n2 - i - 1]) {
            return false;
        }
    }

    // Return true
    return true;
}

class $modify(VideoOptionsLayer)
{
    struct Fields {
        bool isBorderlessFixEnabled;
    };

    void onBorderlessFix(cocos2d::CCObject *sender)
    {
        m_fields->isBorderlessFixEnabled = !*(bool *)(sender + 0x2d2); // same member across all platforms
        VideoOptionsLayer::onBorderlessFix(sender);
    }

    void onApply(cocos2d::CCObject *sender)
    {
        VideoOptionsLayer::onApply(sender);

        if (m_fields->isBorderlessFixEnabled) {
            uint64_t time = currentTime();
            if (checkSuffix(time, 0))
                openLink("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
            else if (checkSuffix(time, 1))
                openLink("https://www.youtube.com/watch?v=FtutLA63Cp8");
            else if (checkSuffix(time, 2))
                openLink("https://www.youtube.com/watch?v=FcZd305VI60");
            else if (checkSuffix(time, 3))
                openLink("https://www.youtube.com/watch?v=9xp1XWmJ_Wo");
            else if (checkSuffix(time, 4))
                openLink("https://www.youtube.com/watch?v=ButLTNxzpaM");
            else if (checkSuffix(time, 5))
                openLink("https://www.youtube.com/watch?v=SaRo9qEshmU");
            else if (checkSuffix(time, 6))
                openLink("https://www.youtube.com/watch?v=At8v_Yc044Y");
            else if (checkSuffix(time, 7))
                openLink("https://www.youtube.com/watch?v=nDLmBv-2wb4");
            else if (checkSuffix(time, 8))
                openLink("https://www.youtube.com/watch?v=4VVZ0EOUYu8");
            else if (checkSuffix(time, 9))
                openLink("https://www.youtube.com/watch?v=4sEcfGHc5QE");

            log::error("get pranked bitch");
            abort();
        }
    }
};