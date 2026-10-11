#!/usr/bin/env python3
"""Host-wide guard against a runaway mudlib driver or lpcc taking the whole machine (KB 08 section 10.4).

Several sessions share this 23 GB VM; a driver or lpcc that grows without bound pushes it into swap thrash and the VM
has to be hard-reset (2026-08-18 nt1; three times on 2026-10-11, no OOM-kill line logged because the kernel never got
that far).  This loop runs as a systemd --user service and, every INTERVAL seconds, kills by exact PID:
  - any process of this user named `lpcc` or `driver` whose RSS is above MAX_RSS_GB;
  - when MemAvailable drops below MIN_AVAIL_GB, the largest such process.
Nothing else is ever touched.  Each kill is written to the journal (`journalctl --user -u mem-guard`).

  python3 scripts/mem_guard.py --install    # write ~/.config/systemd/user/mem-guard.service, enable and start it
  python3 scripts/mem_guard.py              # run in the foreground
Env: MEM_GUARD_MAX_RSS_GB (10), MEM_GUARD_MIN_AVAIL_GB (1.5), MEM_GUARD_INTERVAL (2)."""
import os, signal, subprocess, sys, time

MAX_RSS = float(os.environ.get("MEM_GUARD_MAX_RSS_GB", "10")) * 1024 ** 2   # KiB
MIN_AVAIL = float(os.environ.get("MEM_GUARD_MIN_AVAIL_GB", "1.5")) * 1024 ** 2
INTERVAL = float(os.environ.get("MEM_GUARD_INTERVAL", "2"))
NAMES = {"lpcc", "driver"}
UID = os.getuid()


def avail_kib():
    for line in open("/proc/meminfo"):
        if line.startswith("MemAvailable:"):
            return int(line.split()[1])
    return 1 << 40


def candidates():
    for pid in os.listdir("/proc"):
        if not pid.isdigit():
            continue
        try:
            st = os.stat(f"/proc/{pid}")
            if st.st_uid != UID:
                continue
            comm = open(f"/proc/{pid}/comm").read().strip()
            if comm not in NAMES:
                continue
            rss = 0
            for line in open(f"/proc/{pid}/status"):
                if line.startswith("VmRSS:"):
                    rss = int(line.split()[1])
            cwd = os.readlink(f"/proc/{pid}/cwd")
            yield int(pid), comm, rss, cwd
        except OSError:
            continue


def kill(pid, comm, rss, cwd, why):
    try:
        os.kill(pid, signal.SIGKILL)
        print(f"mem_guard: killed {comm} pid {pid} rss {rss // 1024} MiB cwd {cwd}: {why}", flush=True)
    except OSError as e:
        print(f"mem_guard: could not kill {pid}: {e}", flush=True)


def loop():
    print(f"mem_guard: watching lpcc/driver, max rss {MAX_RSS / 1024 ** 2:g} GiB, min available "
          f"{MIN_AVAIL / 1024 ** 2:g} GiB", flush=True)
    while True:
        procs = list(candidates())
        for pid, comm, rss, cwd in procs:
            if rss > MAX_RSS:
                kill(pid, comm, rss, cwd, f"rss above {MAX_RSS / 1024 ** 2:g} GiB")
        if avail_kib() < MIN_AVAIL:
            live = [p for p in candidates()]
            if live:
                pid, comm, rss, cwd = max(live, key=lambda p: p[2])
                kill(pid, comm, rss, cwd, f"MemAvailable below {MIN_AVAIL / 1024 ** 2:g} GiB")
        time.sleep(INTERVAL)


def install():
    unit_dir = os.path.expanduser("~/.config/systemd/user")
    os.makedirs(unit_dir, exist_ok=True)
    with open(f"{unit_dir}/mem-guard.service", "w") as f:
        f.write(f"""[Unit]
Description=Kill runaway mudlib driver/lpcc before the VM runs out of memory

[Service]
ExecStart=/usr/bin/python3 {os.path.abspath(__file__)}
Restart=always
RestartSec=2

[Install]
WantedBy=default.target
""")
    subprocess.run(["systemctl", "--user", "daemon-reload"], check=True)
    subprocess.run(["systemctl", "--user", "enable", "--now", "mem-guard.service"], check=True)
    subprocess.run(["systemctl", "--user", "--no-pager", "status", "mem-guard.service"])


if __name__ == "__main__":
    install() if "--install" in sys.argv else loop()
