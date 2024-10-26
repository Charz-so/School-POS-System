#pragma once

#if defined(LINUX_PLATFORM) || defined(MAC_PLATFORM)
#include <unistd.h>

#elif defined(WINDOWS_PLATFORM)
#include <windows.h>

#else
#error "Unsupported platform!"

#endif

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

class Screen {
   public:
    using SubscriberCallback = function<void()>;

   private:
    unsigned int width;
    unsigned int height;

    vector<SubscriberCallback> subscribers;

   public:
    Screen();
    ~Screen();

   private:
    void notify();

   public:
    void updateScreenDimensions();
    void subscribe(SubscriberCallback);
    void unsubscribe(SubscriberCallback);

   public:
    unsigned int getWidth() const noexcept;
    void setWidth(unsigned int);

    unsigned int getHeight() const noexcept;
    void setHeight(unsigned int);
};

Screen& getScreen();
void initializeScreen();