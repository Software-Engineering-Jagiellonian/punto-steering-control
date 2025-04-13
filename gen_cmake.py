# gen_cmake.py
import os

def generate_cmakelists(path):
    cmake_file = os.path.join(path, "CMakeLists.txt")
    sources = [f for f in os.listdir(path) if f.endswith(".cpp") or f.endswith(".c")]
    if sources:
        with open(cmake_file, "w") as f:
            f.write(f"cmake_minimum_required(VERSION 3.10)\n")
            f.write(f"project({os.path.basename(path)})\n")
            f.write(f"add_executable({os.path.basename(path)} {' '.join(sources)})\n")

    for dir in os.listdir(path):
        full_path = os.path.join(path, dir)
        if os.path.isdir(full_path):
            generate_cmakelists(full_path)

generate_cmakelists(".")
