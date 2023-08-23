# -*- coding: utf-8 -*-
# @Author: Tairan Gao
# @Date:   2023-06-13 00:56:38
# @Last Modified by:   Tairan Gao
# @Last Modified time: 2023-08-23 10:31:21

import os


def generate_file_list(folder_path):
    file_list = os.listdir(folder_path)
    file_list = sorted(file_list)  # Sort the file list by name
    py_files = []
    cpp_files = []

    for file_name in file_list:
        file_path = os.path.join(folder_path, file_name)
        if os.path.isfile(file_path):
            if file_name.endswith(".py"):
                py_files.append((file_name, file_path))
            elif file_name.endswith(".cpp"):
                cpp_files.append((file_name, file_path))

    md_content = "# Leetcode Pracetice Questions in Folder\n\nNote this is not a full list, only the ones I want to use debugger \n\n [My Profile](https://leetcode.com/GuG_Shadamu/) \n\n"

    if py_files:
        md_content += "## Python Files\n\n"
        for py_file_name, py_file_path in py_files:
            relative_path = py_file_path.split("/")[-1]
            md_content += f"- [{py_file_name}]({relative_path})\n\n"

    if cpp_files:
        md_content += "## C++ Files\n\n"
        for cpp_file_name, cpp_file_path in cpp_files:
            relative_path = cpp_file_path.split("/")[-1]
            md_content += f"- [{cpp_file_name}]({relative_path})\n\n"

    # Add a separator between sections
    if py_files and cpp_files:
        md_content += "---\n"

    readme_file = os.path.join(folder_path, "README.md")
    with open(readme_file, "w") as file:
        file.write(md_content)


# Specify the folder path
folder_path = "/home/tairan-ubuntu/git/Quant-Study/leetcode/"

# Generate the file list
generate_file_list(folder_path)
