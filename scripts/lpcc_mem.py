"""Hard memory cap for every lpcc / driver run the repo scripts start.

An object that recurses or builds without bound makes one lpcc batch grow until the host runs out of memory and has to
be hard-reset (2026-08-18 nt1, 2026-10-11 twice while several sessions ran scans at once).  RLIMIT_AS turns that into
one failed batch instead: the scripts already resume after an object that kills the VM.

  subprocess.run([LPCC, ...], preexec_fn=lpcc_mem.cap)      # Python
  ( ulimit -v "$(python3 scripts/lpcc_mem.py)"; lpcc ... )  # shell (KiB)

LPCC_MEM_GB sets the cap (default 6, which every lib's chunked scan fits in; the machine has 23 GB and two or three
sessions may scan at once)."""
import os, resource, sys

LIMIT_GB = float(os.environ.get("LPCC_MEM_GB", "6"))


def cap():
    n = int(LIMIT_GB * 1024 ** 3)
    resource.setrlimit(resource.RLIMIT_AS, (n, n))


if __name__ == "__main__":
    print(int(LIMIT_GB * 1024 * 1024))   # KiB, for `ulimit -v`
    sys.exit(0)
