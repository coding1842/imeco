#ifndef TEST_H
#define TEST_H

#define MAX_SIZE 100

// 메시지 큐 메시지 구조체
struct msg_buffer {
    long msg_type;
    int data;
};

// Writing 프로세스 함수
void writing_process();

// Reading 프로세스 함수
void reading_process();

#endif /* TEST_H */

