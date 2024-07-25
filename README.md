**Build Your Plugin**

   ```bash
   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Release ..
   cmake --build .
   ```

   This process will compile your code and produce a shared library that Endstone servers can load.

   **Note: If you wish to build against a specific version of Endstone, you can modify the `GIT_TAG` in
   the `CMakeLists.txt` file to point to the desired tag or commit.**
