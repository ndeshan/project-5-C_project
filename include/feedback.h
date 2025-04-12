#ifndef FEEDBACK_H
#define FEEDBACK_H

typedef struct
{
    int patient_id;
    int rating;
    char feedback_text[200];
} Feedback;

void submitFeedback();
void viewFeedback();

#endif