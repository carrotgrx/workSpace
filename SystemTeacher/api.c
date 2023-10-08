//
// Created by carrotgrx on 2023/10/6.
//

#include <stdarg.h>
#include "lib.h"
#include "api.h"

User Users = NULL;
Course Courses = NULL;
Teacher Teachers = NULL;
Homework Homeworks = NULL;
Tutor Tutors = NULL;
Student Students = NULL;


void initApi() {
    Users = createUser();
    Courses = createCourse();
    Teachers = createTeacher();
    Homeworks = createHomework();
    Tutors = createTutor();
    Students = createStudent();
}

//创建新结点

User createUser(void) {
    User user = (User) malloc(sizeof(struct user));
    user->left = NULL;
    user->right = NULL;
    return user;
}

Course createCourse(void) {
    Course course = (Course) malloc(sizeof(struct course));
    course->left = NULL;
    course->right = NULL;
    return course;
}

Teacher createTeacher(void) {
    Teacher teacher = (Teacher) malloc(sizeof(struct teacher));
    teacher->left = NULL;
    teacher->right = NULL;
    return teacher;
}

Homework createHomework(void) {
    Homework homework = (Homework) malloc(sizeof(struct homework));
    homework->left = NULL;
    homework->right = NULL;
    return homework;
}

Tutor createTutor(void) {
    Tutor tutor = (Tutor) malloc(sizeof(struct tutor));
    tutor->left = NULL;
    tutor->right = NULL;
    return tutor;
}

Student createStudent(void) {
    Student student = (Student) malloc(sizeof(struct student));
    student->left = NULL;
    student->right = NULL;
    return student;
}

//插入新结点

void insertCourse(Course course) {
    if (Courses == NULL) {
        Courses = course;
        return;
    }
    Course temp = Courses;
    while (temp != NULL) {
        if (course->id < temp->id) {
            if (temp->left == NULL) {
                temp->left = course;
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = course;
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

void insertTeacher(Teacher teacher) {
    if (Teachers == NULL) {
        Teachers = teacher;
        return;
    }
    Teacher temp = Teachers;
    while (temp != NULL) {
        if (teacher->id < temp->id) {
            if (temp->left == NULL) {
                temp->left = teacher;
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = teacher;
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

void insertHomework(Homework homework) {
    if (Homeworks == NULL) {
        Homeworks = homework;
        return;
    }
    Homework temp = Homeworks;
    while (temp != NULL) {
        if (homework->id < temp->id) {
            if (temp->left == NULL) {
                temp->left = homework;
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = homework;
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

void insertTutor(Tutor tutor) {
    if (Tutors == NULL) {
        Tutors = tutor;
        return;
    }
    Tutor temp = Tutors;
    while (temp != NULL) {
        if (tutor->id < temp->id) {
            if (temp->left == NULL) {
                temp->left = tutor;
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = tutor;
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

void insertStudent(Student student) {
    if (Students == NULL) {
        Students = student;
        return;
    }
    Student temp = Students;
    while (temp != NULL) {
        if (student->id < temp->id) {
            if (temp->left == NULL) {
                temp->left = student;
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = student;
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

//删除结点
void deleteCourse(int id) {
    Course temp = Courses;
    Course parent = NULL;
    while (temp != NULL) {
        if (id < temp->id) {
            parent = temp;
            temp = temp->left;
        } else if (id > temp->id) {
            parent = temp;
            temp = temp->right;
        } else {
            break;
        }
    }
    if (temp == NULL) {
        return;
    }
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            Courses = NULL;
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (temp->left == NULL) {
        if (parent == NULL) {
            Courses = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
    } else if (temp->right == NULL) {
        if (parent == NULL) {
            Courses = temp->left;
        } else if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
    } else {
        Course successor = temp->right;
        Course successorParent = temp;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        temp->id = successor->id;
        strcpy(temp->name, successor->name);
        temp->credit = successor->credit;
        memcpy(temp->teacher_id, successor->teacher_id, sizeof(successor->teacher_id));
        memcpy(temp->student_id, successor->student_id, sizeof(successor->student_id));
        memcpy(temp->grade, successor->grade, sizeof(successor->grade));
        memcpy(temp->evaluation, successor->evaluation, sizeof(successor->evaluation));
        free(successor);
    }
}

void deleteTeacher(int id) {
    Teacher temp = Teachers;
    Teacher parent = NULL;
    while (temp != NULL) {
        if (id < temp->id) {
            parent = temp;
            temp = temp->left;
        } else if (id > temp->id) {
            parent = temp;
            temp = temp->right;
        } else {
            break;
        }
    }
    if (temp == NULL) {
        return;
    }
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            Teachers = NULL;
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (temp->left == NULL) {
        if (parent == NULL) {
            Teachers = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
    } else if (temp->right == NULL) {
        if (parent == NULL) {
            Teachers = temp->left;
        } else if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
    } else {
        Teacher successor = temp->right;
        Teacher successorParent = temp;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        temp->id = successor->id;
        strcpy(temp->name, successor->name);
        strcpy(temp->emile, successor->emile);
        free(successor);
    }
}

void deleteHomework(int id) {
    Homework temp = Homeworks;
    Homework parent = NULL;
    while (temp != NULL) {
        if (id < temp->id) {
            parent = temp;
            temp = temp->left;
        } else if (id > temp->id) {
            parent = temp;
            temp = temp->right;
        } else {
            break;
        }
    }
    if (temp == NULL) {
        return;
    }
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            Homeworks = NULL;
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (temp->left == NULL) {
        if (parent == NULL) {
            Homeworks = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
    } else if (temp->right == NULL) {
        if (parent == NULL) {
            Homeworks = temp->left;
        } else if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
    } else {
        Homework successor = temp->right;
        Homework successorParent = temp;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        temp->id = successor->id;
        temp->course_id = successor->course_id;
        temp->teacher_id = successor->teacher_id;
        strcpy(temp->content, successor->content);
        strcpy(temp->deadline, successor->deadline);
        temp->status = successor->status;
        free(successor);
    }
}

void deleteTutor(int id) {
    Tutor temp = Tutors;
    Tutor parent = NULL;
    while (temp != NULL) {
        if (id < temp->id) {
            parent = temp;
            temp = temp->left;
        } else if (id > temp->id) {
            parent = temp;
            temp = temp->right;
        } else {
            break;
        }
    }
    if (temp == NULL) {
        return;
    }
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            Tutors = NULL;
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (temp->left == NULL) {
        if (parent == NULL) {
            Tutors = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
    } else if (temp->right == NULL) {
        if (parent == NULL) {
            Tutors = temp->left;
        } else if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
    } else {
        Tutor successor = temp->right;
        Tutor successorParent = temp;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        temp->id = successor->id;
        temp->course_id = successor->course_id;
        temp->teacher_id = successor->teacher_id;
        strcpy(temp->time, successor->time);
        free(successor);
    }
}

void deleteStudent(int id) {
    Student temp = Students;
    Student parent = NULL;
    while (temp != NULL) {
        if (id < temp->id) {
            parent = temp;
            temp = temp->left;
        } else if (id > temp->id) {
            parent = temp;
            temp = temp->right;
        } else {
            break;
        }
    }
    if (temp == NULL) {
        return;
    }
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            Students = NULL;
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (temp->left == NULL) {
        if (parent == NULL) {
            Students = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
    } else if (temp->right == NULL) {
        if (parent == NULL) {
            Students = temp->left;
        } else if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
    } else {
        Student successor = temp->right;
        Student successorParent = temp;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        temp->id = successor->id;
        strcpy(temp->name, successor->name);
        strcpy(temp->emile, successor->emile);
        temp->class = successor->class;
        memcpy(temp->course_id, successor->course_id, sizeof(successor->course_id));
        memcpy(temp->grade, successor->grade, sizeof(successor->grade));
        free(successor);
    }
}

//查找结点
Course findCourse(int id) {

}
