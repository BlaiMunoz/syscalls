#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char* file_path = "test.txt";
    const char* message = "Hello, world!\n";
    const int message_size = 14;  // don't forget the newline character!

    // Open the file for writing
    int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Write the message to the file
    int write_result = write(fd, message, message_size);
    if (write_result == -1) {
        perror("Failed to write to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    // Open the file for reading
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Read the message from the file
    char read_buffer[message_size];
    int read_result = read(fd, read_buffer, message_size);
    if (read_result == -1) {
        perror("Failed to read from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    // Print the message to the console
    write(STDOUT_FILENO, read_buffer, read_result);

    return 0;
}
