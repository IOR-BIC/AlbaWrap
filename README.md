# AlbaWrap

**AlbaWrap** is a Python wrapper for the [ALBA Library](https://github.com/IOR-BIC/Alba), designed to expose its core functionalities in a way that can be seamlessly utilized in Python environments. This project aims to bridge the gap between C++ implementations of ALBA and Python developers.

---

## Features

- **Efficient Wrapping**: Access ALBA functionalities without delving into complex C++ implementations.
- **Python-Friendly API**: Intuitive APIs for developers familiar with Python.
- **Cross-Platform Compatibility**: Compatible with major operating systems.
- **Extendable**: Designed for easy extension to accommodate new features from ALBA.

---

## Requirements

Before using AlbaWrap, ensure that you have the following dependencies installed:

- **ALBA Library**: [GitHub Repository](https://github.com/IOR-BIC/Alba)
- **Python**: Version 3.7 or later
- **CMake**: Version 3.16 or later
- **GCC/Clang/MSVC**: A supported C++ compiler
- **SWIG**: For generating Python bindings

You can install these requirements via your package manager (e.g., `apt`, `brew`, `choco`) or manually download them from their official websites.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/IOR-BIC/AlbaWrap.git
   cd AlbaWrap
   ```

2. Initialize and update submodules:
   ```bash
   git submodule update --init --recursive
   ```

3. Build the project:
   ```bash
   mkdir build && cd build
   cmake .. -DALBA_DIR=/path/to/ALBA
   make
   ```

4. Install the Python bindings:
   ```bash
   python setup.py install
   ```

---

## Usage

Once installed, you can start using AlbaWrap in your Python scripts. Below is a basic example:

```python
import albawrap

# Initialize AlbaWrap
albawrap.initialize()

# Example usage
result = albawrap.some_function(param1, param2)
print("Result:", result)

# Finalize AlbaWrap
albawrap.finalize()
```


## Contributing

Contributions are welcome! If you'd like to contribute to AlbaWrap, please follow these steps:

1. Fork the repository.
2. Create a feature branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m 'Add feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Open a pull request.

Please ensure your code adheres to the project's coding standards and includes relevant tests.

---

## License

AlbaWrap use license agreement

This is an open-source copyright as follows:

Redistribution and use in source and binary forms, with or without modification, are permitted 
provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this list of conditions 
and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions
 and the following disclaimer in the documentation and/or other materials provided with the 
 distribution.
* Modified source versions must be plainly marked as such, and must not be misrepresented as 
being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS' AND ANY EXPRESS OR 
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---

## Acknowledgments

AlbaWrap is developed and maintained by [IOR-BIC](https://github.com/IOR-BIC). Special thanks to the contributors of the [ALBA Library](https://github.com/IOR-BIC/Alba) for their foundational work.

---

## Contact

For questions, suggestions, or issues, please open an issue in this repository or contact the maintainers via email: `support@ior-bic.org`.
