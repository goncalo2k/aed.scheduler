#include "../headers/request.h"

Request::Request(std::string type, std::string student_id, std::string uc_code, std::string initial_class_code,
                 std::string final_class_code) {
    this->type = type;
    this->student_id = student_id;
    this->uc_code = uc_code;
    this->initial_class_code = initial_class_code;
    this->final_class_code = final_class_code;
};

string Request::getType() {
    return this->type;
}

string Request::getStudentId() {
    return this->student_id;
}

string Request::getUCCode() {
    return this->uc_code;
}

string Request::getInitialClassCode() {
    return this->initial_class_code;
}

string Request::getFinalClassCode() {
    return this->final_class_code;
}

void Request::setType(string type) {
    this->type = type;
}

void Request::setStudentId(string id) {
    this->student_id = id;
}

void Request::setUCCode(string code) {
    this->uc_code = code;
}

void Request::setInitialClassCode(string code) {
    this->initial_class_code = code;
}

void Request::setFinalClassCode(string code) {
    this->final_class_code = code;
}
