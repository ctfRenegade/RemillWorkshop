#include <cstdlib>

#include "utility.hpp"

using namespace llvm;

static void ProcessModule(Module &M) {
  // TODO: do something meaningful here

  uint64_t cinst = 0;
  uint64_t cbb = 0;

  for (Function &F : M.functions()) {
    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {

        ++cinst;

        if (auto Load = dyn_cast<LoadInst>(&I)) {
        }
      }
      ++cbb;

      outs() << "BB " << BB.getName() << ": " << cinst << "\n";

      cinst = 0;
    }

    // printf("Function %s has %lu basic blocks\n", F.getName(), cbb);
  }
}

int main(int argc, char **argv) {
  // Parse arguments
  if (argc < 2) {
    printf("Usage: %s in.bc [out.bc]\n", std::filesystem::path(argv[0]).filename().c_str());
    return EXIT_FAILURE;
  }
  auto inFile = argv[1];
  auto outFile = argc > 2 ? argv[2] : nullptr;

  // Load module
  LLVMContext C;
  auto M = LoadModule(C, inFile);

  // Process module
  try {
    ProcessModule(*M);
  } catch (const std::exception &x) {
    outs() << x.what() << "\n";
    return EXIT_FAILURE;
  }

  // Save module
  if (outFile != nullptr) {
    SaveModule(M.get(), outFile);
  }

  return EXIT_SUCCESS;
}
