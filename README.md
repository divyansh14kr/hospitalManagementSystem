# Hospital Management System

This C++ program simulates a basic hospital management system, allowing for the admission of patients to different wards and generating bills.

## Table of Contents

- [Classes](#classes)
- [Usage](#usage)
- [Menu Options](#menu-options)
- [Improvements](#improvements)
- [Contributing](#contributing)

## Classes

1. `paitentRecords`: Represents a patient's records. Contains member variables for patient details and functions for recording symptoms, medical history, medicines, etc.

2. `Hospital`: Represents the hospital. Contains functions for admitting patients and generating bills. Maintains an array of patient records.

3. `Orthopedics`, `Cardiology`, `Pediatrics`: Specialized departments inheriting from `Hospital` with specific fee structures.

4. `Doctors`: Represents a doctor with specialization and ID. Inherits from both `paitentRecords` and `Hospital`.

## Usage

1. Compile the code using a C++ compiler.

2. Run the compiled executable.

3. Follow the menu options to interact with the program.

## Menu Options

The program presents the following options:

1. General Ward
2. Pediatrics
3. Cardiology
4. Orthopedics
5. Exit

Within each ward, the user can choose to admit a patient or generate a bill.

## Improvements

- Add input validation to handle invalid user inputs.
- Implement error handling for unexpected scenarios.
- Enhance the program with additional features as needed.

## Contributing

If you'd like to contribute to the project, feel free to fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
