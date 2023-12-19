#pragma once

#ifndef INCLUDE_CONTROL_H_
#define INCLUDE_CONTROL_H_

class Control {
        bool is_up_ = false;
        bool is_down_ = false;
        bool is_left_ = false;
        bool is_right_ = false;
        bool is_exit_ = false;

 public:
        bool IsUP() const;
        bool IsDown() const;
        bool IsLeft() const;
        bool IsRight() const;
        bool IsExit() const;
        void Update();
};

#endif  // INCLUDE_CONTROL_H_
